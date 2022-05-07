#include<stdio.h>
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x>y?y:x
int main(void){
    int p;
    int len, n;
    scanf("%d", &len);
    scanf("%d", &n);
    int minan=0, minans=0, maxan=0, maxans=0;
    for (int i = 0; i < n;i++){
        scanf("%d",&p);
        minan = MIN(p, len - p + 1);
        minans = MAX(minans, minan);
        maxan = MAX(p, len - p + 1);
        maxans = MAX(maxans, maxan);
    }
    printf("%d %d", minans, maxans);
}