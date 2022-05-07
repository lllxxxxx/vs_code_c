#include<bits/stdc++.h>

using namespace std;

// void getNext(string t, int next[]);

void getNext(string t,int next[]){
    int j = 0, k = -1;
    next[0] = -1;
    int c = (int)t.length();
    while(j<c-1){
        if(k==-1||t[j]==t[k]){
            j++;
            k++;
            if(t[j]==t[k])
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
}

int main(){
    string a = "ABABAAABABAA";
    int next[13];
    getNext(a, next);
    for (int i = 0; i < 13;i++){
        cout << next[i] << endl;
    }
    
}