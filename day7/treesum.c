#include<stdio.h>
int score[30];
long long f[30][30];
int root[30][30];
long long dfs(int start, int end);
void print(int l, int r);
int main(void){
    int n;
    long long ans1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &score[i]);
    }
    ans1 = dfs(1, n);
    printf("%lld\n", ans1);
    // for (int i = 0; i < 30;i++){
    //     for (int j = 0; j < 30;j++){
    //         root[i][j] += 1;
    //     }
    // }
    print(1, n);
}

long long dfs(int start,int end){
    if(end<start){
        return 1;
    }
    if((end-start)==0){
        return score[start];
    }
    for (int i = start; i <=end;i++){
        long long c = dfs(start,i-1) * dfs(i + 1, end)+score[i] ;
        if(f[start][end]<c){
            f[start][end] = c;
            root[start][end] = i;
        }
    }
    return f[start][end];
}

void print(int l,int r){
    if(l>r){
        return;
    }
    if(l==r){
        printf("%d ",l);
        return;
    }
    int index = root[l][r];
    printf("%d ", index);
    print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}
