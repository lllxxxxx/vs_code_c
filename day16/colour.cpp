#include<bits/stdc++.h>

using namespace std;

vector<int> g[100];
int colour[100];
int v;

bool dfs(int v,int c){
    colour[v] = c;
    for (int i = 0; i < g[v].size();i++){
        if(colour[g[v][i]]==c)
            return false;
        if(colour[g[v][i]]==0&&!dfs(g[v][i],-c))
            return false;
    }
    return true;
}

void solve(){
    for (int i = 0; i < v;i++){
        if(colour[i]==0){
            if(!dfs(i,1)){
                printf("no");
                return;
            }
        }
    }
    printf("yes");
}