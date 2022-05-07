#include<stdio.h>
#include<stdlib.h>

#define maxn 10
#define inf 1000

typedef struct graph{
    char vexs[maxn];
    int vexnum;
    int edgnum;
    int matirx[maxn][maxn];
}graph;

int path[maxn][maxn];
int s[maxn][maxn];

void floyed(graph g,int p[][maxn],int d[][maxn]){
    for (int v = 0; v < g.vexnum;v++){
        for (int w = 0; w < g.vexnum;w++){
            d[v][w] = g.matirx[v][w];
            p[v][w] = w;
        }
    }
    for (int k = 0; k < g.vexnum;k++){
        for (int v = 0; v < g.vexnum;v++){
            for (int w = 0; w < g.vexnum;w++){
                if(d[v][w]>(d[v][k]+d[k][w])){
                    d[v][w] = d[v][k] + d[k][w];
                    p[v][w] = p[v][k];
                }
            }
        }
    }
}