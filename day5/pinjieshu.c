#include<stdio.h>

static int ans = 1;
void count(int n);
int main(void){
    int n;
    scanf("%d", &n);
    count(n);
    printf("%d", ans);
    return 0;
}

void count(int n){
    for (int i = 1; i <= n / 2;i++){
        ans += 1;
        count(i);
    }
}