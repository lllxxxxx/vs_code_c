#include<stdio.h>
const int MAX = 10000 + 5;
int a[MAX], b[MAX], c[MAX], d[MAX];

int main(void){
    int n, x, y;
    scanf("%d", &n);
    int ans = -1;
    
    for (int i = 0; i < n;i++){
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }

    scanf("%d%d", &x, &y);

    for (int i = 0; i < n;i++){
        if(x>=a[i]&&x<=(a[i]+c[i])&&y>=b[i]&&y<=(b[i]+d[i])){
            ans += 1;
        }
    }
    printf("%d", ans);
    return 0;
}