#include<stdio.h>
void dfs(int index, long long free,int *first,int *last);

int n;
long long ans=0;

int main(void){
    int c;
    int first[100]={0}, last[100]={0};
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &c);
        first[i] = c;
        last[i- 1] = c;
    }
    last[n] = first[1];
    last[0] = 0;
    dfs(0, 0,first,last);
    printf("%lld", ans);
}

void dfs(int index,long long free,int *first,int *last){
    if(index==n-1){
       
        if (ans < free)
        {
            ans = free;
        }
        return;
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j<=n;j++){
            if(last[i]==first[j]&&i!=j&&first[j]!=0&&last[i]!=0){
                int f1[100]={0}, l1[100]={0};
                for (int k = 0; k < 100;k++){
                    f1[k] = first[k];
                    l1[k] = last[k];
                }
                l1[i] = last[j];
                int c = first[j];
                l1[j] = 0;
                f1[j] = 0;
                dfs(index + 1, free + first[i] * c * last[j],f1,l1);
            }
        }
    }
}