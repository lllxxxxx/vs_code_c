#include<stdio.h>

int main(){
    int data[10], dp[10],n;
    for (int i = 1; i <= n;i++){
        dp[i] = 1;
        for (int j = 1; j < i;j++){
            if(data[j]<data[i]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }
}