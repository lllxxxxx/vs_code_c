#include<stdio.h>
#define maxe 100
#define maxv 100

typedef struct{
    int vex1;
    int vex2;
    int weight;
} Edge;

void k(Edge edge[],int n,int e){
    int vset[n + 1];
    int m1, m2,sum=0,sn1,sn2;
    for (int i = 0; i <= n;i++)
        vset[i] = i;
    int k = 1;
    int j = 0;
    while(k<e){
        m1 = edge[j].vex1;
        m2 = edge[j].vex2;
		sn1 = vset[m1];
		sn2 = vset[m2];
		if(sn1!=sn2){
            printf("v%d-v%d=%d\n", m1, m2, edge[j].weight);
            sum += edge[j].weight;
            k++;
            if(k>=n)
                break;
            for(int i=1;i<=n;i++)
				if (vset[i]==sn2) 
					vset[i]=sn1;
        }
         j++;
    }
    printf("max=%d\n", sum);
}

int fun(Edge arr[],int low,int high)
 {
 	int key;
 	Edge lowx;
 	lowx=arr[low];
 	key=arr[low].weight;
 	while(low<high)
 	{
 		while(low<high && arr[high].weight>=key)
 			high--;
 		if(low<high)
 			arr[low++]=arr[high];

 		while(low<high && arr[low].weight<=key)
 			low++;
 		if(low<high)
 			arr[high--]=arr[low];
	 }
	 arr[low]=lowx;
	 return low;
  } 
void quick_sort(Edge arr[],int start,int end)
{
	int pos;
	if(start<end)
	{
	pos=fun(arr,start,end);
	quick_sort(arr,start,pos-1);
	quick_sort(arr,pos+1,end);
	}
}

void Kruskal(Edge E[],int numn,int nume){
	quick_sort(E,0,nume-1);
	k(E,numn,nume);
}

int main()
{
	Edge E[maxe];
	int nume,numn;
    //freopen("1.txt","r",stdin);//文件输入
	printf("输入顶数和边数:\n");
	scanf("%d%d",&numn,&nume);
	for(int i=0;i<nume;i++)
		scanf("%d%d%d",&E[i].vex1,&E[i].vex2,&E[i].weight);
	Kruskal(E, numn, nume);
}
