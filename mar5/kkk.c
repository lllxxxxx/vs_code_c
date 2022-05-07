#include<stdio.h>
#include<math.h>

#define maxn 20
#define max(a, b) a > b ? a : b

int sub = 9999;
int to1;

void dfs(int to[][maxn], int index, int sum1, int sum2, int n, int ssn);

void dfs(int to[][maxn],int index,int sum1,int sum2,int n,int ssn){  //传入俩数组和两个数组的和 差 
    if(index>=ssn){
        if(sub>abs(sum1-sum2)){
            sub = abs(sum1 - sum2);
            to1 = max(sum1,sum2);
            
        }
        return;
    }
    dfs(to, index + 1, sum1 + to[n][index], sum2, n, ssn);
    dfs(to, index + 1, sum1, sum2 + to[n][index], n, ssn);

}

int main(){
    int a[4];
    for (int i = 0; i < 4;i++){
        scanf("%d", &a[i]);
    }
    int to[4][maxn];
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < a[i];j++){
            scanf("%d", &to[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 4;i++){
        if(a[i]==1){
            ans += to[i][0];
        }
        else{ 
            if(a[i]==2){
                ans += max(to[i][0], to[i][1]);
            }
            else{
                dfs(to, 0, 0, 0, i, a[i]);
                ans += to1;
                sub = 9999;
                to1 = 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}