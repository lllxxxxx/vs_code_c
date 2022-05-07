#include<stdio.h>

#define MAX 100
#define maxcost 0x7fffffff

int prim(int graph[][MAX],int n){
    int lowcost[MAX];
    int mst[MAX];
    int i, j, min, minid, sum = 0;
    for (i = 2; i <= n;i++){
        lowcost[i] = graph[1][i];
        mst[i] = 1;
    }
    mst[1] = 0;
    for (i = 2; i <= n;i++){
        min = maxcost;
        minid = 0;
        for (j = 2; j <= n;j++){
            if(lowcost[j]<min&&lowcost[j]!=0){
                min = lowcost[j];
                minid = j;
            }
        }
        printf("v%d-v%d=%d",mst[minid],minid,min);
        sum += min;
        lowcost[minid] = 0;
        for (j = 2; j <= n;j++){
            if(graph[minid][j]<lowcost[j]){
                lowcost[j] = graph[minid][j];
                mst[j] = minid;
            }
        }
    }
    return sum;
}