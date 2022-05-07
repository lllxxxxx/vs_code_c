#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error -1
#define max_var 10
typedef int infoType;
typedef char vexType;
typedef int weightType;
// int locateVex(alGraph *g, vexType v);
typedef int vertex;


typedef enum
{
    dg = 1,
    ag,
    wdg,
    wag
} graphKind;

typedef struct LinkNode{       //链表
    int adjvex;
    infoType info;
    struct LinkNode *nextarc;
} LinkNode;

typedef struct vexNode{
    vexType data;
    int outdegree;
    int indegree;
    LinkNode *firstarc;
} vexNode;



typedef struct{
    graphKind kind;
    int vexnum;                     //顶点个数
    vexNode adjList[max_var];       //储存链表的数组
} alGraph;

//队列
typedef struct sqQueue{
    int array[max_var];
    int front;
    int rear;
} sqQueue;

sqQueue creat_queue(){
    sqQueue q;
    q.front = 0;
    q.rear = 0;
    return q;
}

int insertQueue(sqQueue *q,int e){
    if((q->rear+1)%max_var==q->front){
        printf("full\n");
        return error;
    }else{
        q->array[q->rear] = e;
        q->rear = (q->rear + 1) % max_var;
    }
    return ok;
}

int deleteQueue(sqQueue *q){
    vexType e = 0;
    if(q->front==q->rear){
        printf("empty");
        return error;
    }else{
        e = q -> array[q->front];
        q->front = (q->front + 1) % max_var;
    }
    return e;
}

int IsEmpty(sqQueue *q){
    if(q->front==q->rear){
        printf("empty");
        return 0;
    }else{
        return 0;
    }
}

alGraph creat_graph(){
    alGraph g;
    int i;
    int a = 0;
    printf("1.dg\n2.ag\n3.wdg\n4.wag\n");
    scanf("%d", &a);
    switch(a){
        case 1:
            g.kind = dg;
            break;
        case 2:
            g.kind = ag;
            break;
        case 3:
            g.kind = wdg;
            break;
        case 4:
            g.kind = wag;
            break;
        default:
            printf("error");
            break;
    }
    g.vexnum = 0;
    for (i = 0; i < max_var;i++){
        g.adjList[i].outdegree = 0;
        g.adjList[i].indegree = 0;
        g.adjList[i].firstarc = NULL;
    }
    return g;
}

int locateVex(alGraph *g,vexType v){
    int i = 0;
    int a = 0;
    printf("v=%c\n", v);
    for (i = 0; i < g->vexnum;i++){
        if(g->adjList[i].data==v){
            a++;
            break;
        }
    }
    if(a==0){
        return error;
    }
    return ok;
}

void insertVex(alGraph *g){
    int res = 0;
    if(g->vexnum+1==max_var){
        printf("overflow\n");
    }else{
        vexType u = '\0';
        printf("enter data:\n");
        getchar();
        scanf("%c", &u);
        res = locateVex(g, u);
        if(res==-1){
            g->adjList[g->vexnum].data = u;
            g->adjList[g->vexnum].firstarc = NULL;
            g->vexnum++;

        }else{
            printf("error\n");
        }
    }
}

void insertArc(alGraph *g){
    if(g->kind==dg){
        LinkNode* p;
        LinkNode* r;
        int tail = 0;
        int head = 0;
        p = (LinkNode*)malloc(sizeof(LinkNode));
        printf("enter the tail");
        scanf("%d", &tail);
        printf("enter the head");
        scanf("%d", &head);
        if(tail<g->vexnum&&head<g->vexnum){
            p->adjvex = head;
            p->nextarc = NULL;
            p->info = 0;   //初始化
            r = g->adjList[tail].firstarc;
            p->nextarc = r;
            g->adjList[tail].firstarc = p;
            g->adjList[tail].outdegree++;
            g->adjList[head].indegree++;
            printf("success\n");
        }else{
            printf("error");
        }
    }
    	else if(g->kind == ag)//无向图
	{
		LinkNode *p;
		LinkNode *q;
		LinkNode *r;
		LinkNode *s;
		int tail = 0;
		int head = 0;
		p = (LinkNode *)malloc(sizeof(LinkNode));
		q = (LinkNode *)malloc(sizeof(LinkNode));
		s = (LinkNode *)malloc(sizeof(LinkNode));
		printf("please enter the tail:");
		scanf("%d", &tail);
		printf("please enter the head:");
		scanf("%d", &head);
		if (tail < g->vexnum && head < g->vexnum)
		{
			p->adjvex = head;
			p->info = 0;
			p->nextarc = NULL;
			r = g->adjList[tail].firstarc;
			p->nextarc = r;
			g->adjList[tail].firstarc = p;

			s->adjvex = tail;
			s->info = 0;
			q = g->adjList[head].firstarc;
			s->nextarc = q;
			g->adjList[head].firstarc = s;

			g->adjList[tail].outdegree++;
			g->adjList[head].outdegree++;
            g->adjList[tail].indegree++;
			g->adjList[head].indegree++;
			printf("insert arc success\n");
		}
		else
		{
			printf("vertex is not exit.\n");
		}

	}
	else if (g->kind == wdg)//加权有向图
	{
		LinkNode *p;
		LinkNode *r;
		int info = 0;
		int tail = 0;//弧尾（起点）
		int head = 0;//弧头（终点）
		p = (LinkNode *)malloc(sizeof(LinkNode));
		printf("please enter the tail:");
		scanf("%d", &tail);
		printf("please enter the head:");
		scanf("%d", &head);
		printf("please enter the information:");
		scanf("%d", &info);
		if (tail < g->vexnum && head < g->vexnum)
		{
			p->adjvex = head;
			p->nextarc = NULL;
			p->info = info;
			r = g->adjList[tail].firstarc;
			p->nextarc = r;
			g->adjList[tail].firstarc = p;
			g->adjList[tail].outdegree++;
            g->adjList[head].indegree++;
			printf("insert arc success\n");
		}
		else
		{
			printf("vertex is not exit.\n");
		}

	}
	else if(g->kind == wag)//加权无向图
	{
		LinkNode *p;
		LinkNode *q;
		LinkNode *r;
		LinkNode *s;
		int info = 0;
		int tail = 0;
		int head = 0;
		p = (LinkNode *)malloc(sizeof(LinkNode));
		q = (LinkNode *)malloc(sizeof(LinkNode));
		s = (LinkNode *)malloc(sizeof(LinkNode));
		printf("please enter the tail:");
		scanf("%d", &tail);
		printf("please enter the head:");
		scanf("%d", &head);
		printf("please enter the information:");
		scanf("%d", &info);
		if (tail < g->vexnum && head < g->vexnum)
		{
			p->adjvex = head;
			p->nextarc = NULL;
			p->info = info;
			r = g->adjList[tail].firstarc;
			p->nextarc = r;
			g->adjList[tail].firstarc = p;

			s->adjvex = tail;
			s->info = info;
			q = g->adjList[head].firstarc;
			s->nextarc = q;
			g->adjList[head].firstarc = s;

			g->adjList[tail].outdegree++;
			g->adjList[head].outdegree++;
            g->adjList[tail].indegree++;
			g->adjList[head].indegree++;
			printf("insert arc success\n");
		}
		else
		{
			printf("vertex is not exit.\n");
		}
	}
	else
	{
		printf("The type of the graph is error\n");
	}
}

void dfs(alGraph *g,int v,int visit[]){
    LinkNode *p;
    if(visit[v]==0){
        printf("%c\n", g->adjList[v].data);
        visit[v] = 1;
        p = g->adjList[v].firstarc;
        while(p!=NULL){
            if(visit[p->adjvex]==0){
                dfs(g, p->adjvex, visit);
            }
            p = p->nextarc;
        }
    }
}

void bfs(alGraph *g){
    int i = 0;
    int k = 0;
    sqQueue q = creat_queue();
    int visit[max_var];
    LinkNode *p;
    for (i = 0; i < max_var;i++){
        visit[i] = 0;
    }
    for (k = 0; k < g->vexnum;k++){
        if(visit[k]==0){
            insertQueue(&q, k);
            visit[k] = 1;
            if(g->adjList[k].firstarc!=NULL){
                p = g->adjList[k].firstarc;
                while(p!=NULL){
                    if(visit[p->adjvex]==0){
                        insertQueue(&q, p->adjvex);
                        visit[p->adjvex] = 1;
                    }
                    p = p->nextarc;
                }
            }
        }
        else{
            if(g->adjList[k].firstarc!=NULL){
                p = g->adjList[k].firstarc;
                while(p!=NULL){
                    if(visit[p->adjvex]==0){
                        insertQueue(&q, p->adjvex);
                        visit[p->adjvex] = 1;

                    }
                    p = p->nextarc;
                }
            }
        }
    }
    while(q.front!=q.rear){
        char c = deleteQueue(&q);
        printf("%c\n",c);
    }
}

int destoryGraph(alGraph *g){
    int i = 0;
    for (i = 0; i < g->vexnum;i++){
        g->adjList[i].data = 0;
        g->adjList[i].outdegree = 0;
        g->adjList[i].indegree = 0;
        g->adjList[i].firstarc = NULL;
    }
    g->vexnum = 0;
    return ok;
}

void outdegreePut(alGraph *g){
    int i = 0;
    printf("value/outdegree/indegree/firstarc\n");
    for (i = 0; i < g->vexnum;i++){
        printf("%c\t", g->adjList[i].data);
        printf("%d\t\t", g->adjList[i].outdegree);
        printf("%d\t\t", g->adjList[i].indegree);
        LinkNode *p;
        p = g->adjList[i].firstarc;
        while(p!=NULL){
            printf("->");
            printf("%c\t", g->adjList[p->adjvex].data);
            p = p->nextarc;
        }
        printf("\n");
        printf("-----------------\n");
    }
}

void topSort(alGraph g){
    sqQueue q = creat_queue();
    LinkNode *p;
    int count = 0;
    int c=0;
    for (int i = 0; i < g.vexnum;i++){
        if(g.adjList[i].indegree==0){
            insertQueue(&q, i);
        }
    }
    while(!IsEmpty(&q)){
        c = deleteQueue(&q);
        printf("%d ", c);
        count++;
        p = g.adjList[c].firstarc;
        while(p!=NULL){
            if(g.adjList[p->adjvex].indegree-1==0){
                insertQueue(&q, p->adjvex);
            }
            
            p = p->nextarc;
        }
    }
    if(count!=g.vexnum){
        printf("error");
    }
}

void unWeight(alGraph g,int know[],int dist[],int path[],int s){
    int c = 0;
    sqQueue q = creat_queue();
    dist[s] = 0;
    LinkNode *p;
    insertQueue(&q, s);
    while(!IsEmpty(&q)){
        c = deleteQueue(&q);
        know[c] = 1;
        p = g.adjList[c].firstarc;
        while(p!=NULL){
            if(dist[p->adjvex]==error){
                dist[p->adjvex] = dist[c] + 1;
                path[p->adjvex] = c;
                insertQueue(&q, p->adjvex);
            }
        }
    }
}

int main(){
   alGraph g = creat_graph();
   insertVex(&g);
   insertVex(&g);
   insertArc(&g);
   outdegreePut(&g);
   topSort(g);
   // printf("||||||||||||||||||||||||||||\n");
//    bfs(&g);
// sqQueue q = creat_queue();
// insertQueue(&q, 'c');
// insertQueue(&q, 'q');
// deleteQueue(&q);
// deleteQueue(&q);
}

