#include<bits/stdc++.h>
using namespace std;

int maxSonString(int a[],int from,int to){
    if(from==to)
        return a[to];
    int mid = (from + to) / 2;
    int maxLeft = maxSonString(a, from, mid);
    int maxRight = maxSonString(a, mid + 1, to);
    int now1 = a[mid];
    int resL=a[mid];
    for (int i = mid; i >= from;i--){
        now1 += a[i];
        resL = max(now1, resL);
    }
    int resR = a[mid + 1];
    int now2 = a[mid + 1];
    for (int i = mid + 1; i <= to;i++){
        now2 += a[i];
        resR = max(now2, resR);
    }
    int max_mid = resL + resR;
    return max(max(maxLeft, maxRight), max_mid);
}