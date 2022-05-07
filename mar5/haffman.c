#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef Node *PtrToNode;
typedef struct Data data;
typedef struct HaffmanTree HT;
typedef HT *PtrHT;

#define maxn 100
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b, b = temp;\
}

PtrToNode build(data *arr, int n);
PtrToNode getNewNode(data *obj);
void sort(PtrToNode *nodes, int n);

struct Node{
    PtrToNode left;
    PtrToNode right;
    char data;  //数据域
    double p;   //概率值
};

struct Data{
    char ch;
    double p;
};

struct HaffmanTree{
    PtrToNode root;
};

data arr[maxn + 5];

int main(void){
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }

    PtrToNode tree = build(arr, n);
    return 0;
}


PtrToNode build(data *arr,int n){
    PtrToNode *nodes = (PtrToNode*)malloc(sizeof(PtrToNode) * n);//储存的数组
    for (int i = 0; i < n;i++){
        nodes[i] = getNewNode(arr+i);
    }   //写入 然后就排序
    while(n>1){
        sort(nodes, n);
        PtrToNode p = (PtrToNode)malloc(sizeof(Node));
        p->p = nodes[n - 1]->p + nodes[n - 2]->p;
        p->left = nodes[n - 1];
        p->right = nodes[n - 2];
        p->data = 'a';
        nodes[n - 2] = p;
        // free(nodes[n - 1]);
        n--;
    }
    return nodes[0];
}

PtrToNode getNewNode(data *obj){
    PtrToNode p = (PtrToNode)malloc(sizeof(Node));
    p->data = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->left = p->right = NULL;
    return p;
}

void sort(PtrToNode *nodes,int n){
    // PtrToNode tmp;
    for (int i = 0; i < n;i++){
        for (int j = i; j < n;j++){
            if(nodes[i]->p<nodes[j]->p)
                swap(nodes[i], nodes[j]);
        }
    }
}