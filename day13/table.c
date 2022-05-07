#include<stdio.h>
#include<stdlib.h>
#define max_num 10
#define false 0
#define true 1

#define INF 65535
#define ERROR -65535

typedef int wType;
typedef int dataType;
typedef struct graphNode *ptrToGraphNode;
typedef int bool;
typedef int position;

typedef int ElementType;
int visited[max_num]={false};

struct graphNode{
    int nv;
    int ne;
    wType graph[max_num][max_num];
    dataType data[max_num];
};
typedef ptrToGraphNode mGraph;

typedef int vertex;

mGraph createGraph(int vertexnum){
    vertex v, w;
    mGraph mgraph;
    mgraph = (mGraph)malloc(sizeof(struct graphNode));
    mgraph->nv = vertexnum;
    mgraph->ne = 0;
    for (v = 0; v < mgraph->nv;v++){
        for (w = 0; w < mgraph->nv;w++){
            mgraph->graph[v][w] = 0;
        }
    }
    for (int i = 0; i < mgraph->nv;i++){
        visited[i] = false;
        mgraph->data[i] = i;
    }
    return mgraph;
}

typedef struct eNode *ptrToeNode;
struct eNode{
    vertex v1, v2;
    wType weig;
};
typedef ptrToeNode edGraph;

void insertEd(mGraph g,edGraph e){
    g->graph[e->v1][e->v2] = e->weig;
}

mGraph buildGraph(){
    mGraph Graph;
    edGraph e;
    // vertex v;
    int nv, i;
    scanf("%d", &nv);
    Graph = createGraph(nv);
    scanf("%d",&(Graph->ne));
	if(Graph->ne != 0) {
		e = (edGraph)malloc(sizeof(struct eNode));
		for(i=0;i<Graph->ne;i++) {
			scanf("%d %d %d",&e->v1,&e->v2,&e->weig);
			insertEd(Graph, e);
		}
			
	}
	return Graph;
}

void DijkstraPath(mGraph Graph,int *dist,int *path,int v0)   //v0表示源顶点 
{
    int i,j,k;
    int visited[Graph->nv];
    for(i=0;i<Graph->nv;i++)     //初始化 
    {
        if(Graph->graph[v0][i]>0&&i!=v0)
        {
            dist[i]=Graph->graph[v0][i];
            path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点 
        }
        else
        {
            dist[i]=INT_MAX;    //若i不与v0直接相邻，则权值置为无穷大 
            path[i]=-1;
        }
        visited[i]=false;
        
    }
    path[v0]=v0;
    dist[v0]=0;
    visited[v0]=true;
    for(i=1;i<Graph->nv;i++)     //循环扩展n-1次 
    {
        int min=INT_MAX;
        int u;
        for(j=0;j<Graph->nv;j++)    //寻找未被扩展的权值最小的顶点 
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;        
            }
        } 
        visited[u]=true;
        for(k=0;k<Graph->nv;k++)   //更新dist数组的值和路径的值 
        {
            if(visited[k]==false&&Graph->graph[u][k]>0&&min+Graph->graph[u][k]<dist[k])
            {
                dist[k]=min+Graph->graph[u][k];
                path[k]=u; 
            }
        }        
    }    
}



void d(mGraph Graph,int dist[],int path[],int v0){
    int visit[Graph->nv] ;
    for (int i = 0; i < Graph->nv;i++){
        if(Graph->graph[v0][i]>0&&i!=v0){
            dist[i] =Graph->graph[v0][i];
            path[i] = v0;
        }else{
            dist[i] = INT_MAX;
            path[i] = -1;
        }
        visit[i]=false;
    }
    dist[v0] = 0;
    path[v0] = v0;
    visit[v0] = true;
    
    
    for (int i = 1; i < Graph->nv;i++){
        int min = INT_MAX;
        int u;
        for (int j = 0; j < Graph->nv;j++){
            if(min>dist[j]&&dist[j]!=0&&visit[j]==false){
                min = dist[j];
                u = j;
            }
        }
        visit[u] = true;
        for (int k = 0; k < Graph->nv;k++){
            if(visit[k]==false&&dist[k]>(min+Graph->graph[u][k])&&Graph->graph[u][k]>0){
                dist[k] =min+ Graph->graph[u][k];
                path[k] = u;
            }
        }
    }
}

void PrintPath(int path[],int pt)
{
	int tmp = pt;
	int cnt = 1;
	int collected[max_num] = {0};
	
	while(path[tmp] != 0)
	{
		collected[cnt] = path[tmp];
		cnt++;
		tmp = path[tmp];
		
	}
	collected[cnt] = path[tmp];
	
	while(cnt != 0){
		printf("v%d->",collected[cnt]);
		cnt --;
	}
	printf("v%d",pt);
}

int main(){
    mGraph g = buildGraph();
    int Nv = g->nv;
   
	int dist[Nv];
	int path[Nv];
	d(g,dist,path,0);
	int distance = 5;
	PrintPath(path,distance);
	printf("\ncost distance :%d",dist[distance]);
	return 0;
}