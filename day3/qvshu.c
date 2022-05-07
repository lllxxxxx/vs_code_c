#include<stdio.h>

#define max(x,y) x>y?x:y


int main(void){
    int n,l,a,b,d,a1,a2;
    int c[12][12][12][12]={{{{0}}}},e[10][10]={{0}};
    scanf("%d", &n);
    while(1){
        scanf("%d%d%d",&a,&b,&d);
        if(a==0&&b==0&&d==0){
            break;
        }
        e[a][b] = d;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            for (int k = 1; k <= n;k++){
                l = i + j - k;
                if(l<=0){
                    break;
                }
                a1 = max(c[i][j - 1][k - 1][l], c[i][j - 1][k][l - 1]);
                a2 = max(c[i - 1][j][k][l - 1], a1);
                c[i][j][k][l] = max(c[i - 1][j][k - 1][l], a2)+e[i][j]+e[k][l];
                if(i==k&&j==l){
                    c[i][j][k][l] -= e[k][l];
                }
                
            }
        }
    }
    printf("%d", c[n][n][n][n]);
    return 0;
}