#include<stdio.h>

int main(void){
    int n, m;//棋子
    int l, x;//马的位置
    scanf("%d%d", &n, &m);
    scanf("%d%d", &l, &x);
    l = l + 1;
    x = x + 1;

    int a[30][30]={{1}};

    for (int i = 1; i < 30;i++){
        a[i][1] = 1;
    }
    for (int i = 1; i < 30;i++){
        a[1][i] = 1;
    }

    for (int i = 1; i <=n+1;i++){
        for (int j = 1; j <=m+1;j++){
            if(i==1&&j==1){
                continue;
            }
            if((i==l&&j==x)||(i==l-1&&j==x-2)||(i==l-2&&j==x-1)||(i==l-1&&j==x+2)||(i==l-2&&j==x+1)||(i==l+1&&j==x-2)||(i==l+2&&j==x-1)||(i==l+1&&j==x+2)||(i==l+2&&j==x+1)){
                a[i][j] = 0;
                continue;
            }

            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    printf("%d\n", a[n+1][m+1]);

    return 0;
}