#include<stdio.h>
struct {
    int m;
    int v;
    double av;
} p[100],p1;
int main(void){
    int n, max;
    scanf("%d%d", &n, &max);
    int c1, c2;
    for (int i = 0; i < n;i++){
        scanf("%d%d", &c1, &c2);
        p[i].m = c1;
        p[i].v = c2;
        p[i].av = c2 / c1;
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < i;j++){
            if(p[j].av>p[i].av){
                p1 = p[i];
                p[i] = p[j];
                p[j] = p1;
            }
        }
    }
    double ans=0;
    for (int i = n - 1; max > 0;i--){
        if(p[i].m<=max){
            max -= p[i].m;
            ans += p[i].v;
        }else{
            
            ans += p[i].av * max;
            max = 0;
        }
    }
    printf("%.2lf", ans);
    return 0;
}