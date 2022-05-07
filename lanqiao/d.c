#include<stdio.h>

void f(int v[][20], int n);

#define max(a,b) a>b?a:b

int main(){
    int q[20]={0};
    int n;
    int v[20][20];
    for (int i = 0; i < 20;i++){
        for (int j = 0; j < 20;j++){
            v[i][j] = 9999;
        }
    }
    scanf("%d", &n);
    int a,b,p;
    for (int i = 0; i < n - 1;i++){
        scanf("%d%d%d", &a, &b, &p);
        v[a][b] = p;
        v[b][a] = p;
    }
    f(v, n);
    
    for (int j = 1; j <= n;j++){
        for (int i = 1; i <= n; i++)
        {
            if(v[j][i]>q[i])
                q[i] = v[j][i];
        }
    }
    int ans = 99999;
    int u = 0;
    for (int i = 1; i <= n;i++){
        if(q[i]<ans){
            ans = q[i];
            u = i;
            }
    }
    printf("%d", u);
    return 0;
}

void f(int v[][20],int n){
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= n ;j++){
            for (int k = 0; k <= n;k++){
                if(v[i][k]>(v[i][j]+v[j][k])){
                    v[i][k] = v[i][j] + v[j][k];
                    v[k][i] = v[i][j] + v[j][k];
                }
            }
        }
    }
}

