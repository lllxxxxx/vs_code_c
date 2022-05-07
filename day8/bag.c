#include<stdio.h>
int ans = 9999;
int v[30];
void bag(int c,int index,int max){
    if(c<0){
        return;
    }
    if(index>max){
        return;
    }
    bag(c - v[index + 1], index + 1,max);
    bag(c , index + 1,max);
    if(ans>c){
        ans = c;
    }
}
int main(void){
    int c;
    scanf("%d", &c);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &v[i]);
    }
    bag(c, 0,n);
    printf("%d", ans);
    return 0;
}