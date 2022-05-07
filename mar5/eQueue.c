#include<stdio.h>
#include<stdlib.h>
#include<math.h>

   

int ans=0;

int bool(int visit[], int f);
void dfs(int n, int f,int visit[]);

void dfs(int n,int f,int visit[]){
    if(f>=n){
        ans++;
        if(ans<=3){
            for (int i = 0; i < n;i++){
                printf("%d ",visit[i]+1);
            }
            printf("\n");
        }
        return;
    }
    // int pan[n + 1][n + 1];
    
    for (int i = 0; i < n;i++){
        visit[f] = i;
        if(bool(visit,f))
            dfs(n, f + 1,visit);
    }
    return;
}


int main(){
    int n;
    scanf("%d", &n);
    int visit[10];
    dfs(n,0,visit);
    printf("%d", ans);
    return 0;
}

int bool(int visit[],int f){
    for (int i = 0; i < f;i++){
        if(visit[i]==visit[f]||abs(i-f)==abs(visit[i]-visit[f]))
            return 0;
       
    }
    return 1;
}