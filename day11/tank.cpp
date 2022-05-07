#include<cstdio>
#include<queue>
using namespace std;

int L, P, N;
int a[1000], b[1000];

void solve(){
    a[N] = L;
    b[N] = 0;
    N++;
    priority_queue<int> que;
    int ans = 0, pos = 0, tank = P;
    for (int i = 0; i < N;i++){
        int d = a[i] - pos;
        while(tank-d<0){
            if(que.empty()){
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = a[i];
        que.push(b[i]);

    }
    printf("%d", ans);
}