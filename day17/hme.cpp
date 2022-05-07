#include<bits/stdc++.h>

// #define varType string
// #define edgeType int
// #define Maxnum 100

using namespace std;

// typedef struct graph{
//     varType x[Maxnum];
//     varType y[Maxnum];
//     edgeType edge[Maxnum][Maxnum];
//     int xnum, ynum, edgenum;
// } graph;

// int m[Maxnum];
// bool x[Maxnum], y[Maxnum];
#define maxn 10
int nx, ny;
int g[maxn][maxn];
int cx[maxn], cy[maxn];
int mk[maxn];

int path(int u){
    for (int v = 0; v < ny;v++){
        if(g[u][v]&&!mk[v]){
            mk[v] = 1;
            if(cy[v]==-1||path(cy[v])){
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int maxMatch(){
    int res = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i = 0; i < nx;i++){
        if(cx[i]==-1){
            memset(mk, 0, sizeof(mk));
            res += path(i);
        }
    }
    return res;
}
