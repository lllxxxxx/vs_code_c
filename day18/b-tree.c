#include<stdio.h>
#include<stdlib.h>

#define maxn 20
#define error -1
#define ok 1

typedef int status;
typedef struct B_Tree bTree;
typedef bTree *ptrToNode;
typedef int ElementType;
typedef bTree *BTree;

struct B_Tree{
    int keynum;
    ptrToNode parent;
    int key[maxn];
    ptrToNode ptr[maxn];
    int maxNum;
};

status insert(BTree t,ElementType x){
    BTree p;
    int index, tmp;
    status flag;
    if(t==NULL){
        t = (BTree)malloc(sizeof(bTree));
        if(t==NULL)
            return error;
        t->keynum = 1;
        t->parent = NULL;
        for (index = 0; index < maxn;index++){
            t->key[index] = 0;
            t->ptr[index] = NULL;
        }
        t->key[0] = x;
        return ok;
    }
    else{
        for (int i = 0; x <= t->key[i];i++){
            index = i;
        }
        if(t->ptr[index]!=NULL)
            insert(t->ptr[index], x);
        if(t->keynum==t->maxNum){
            if(t->parent==NULL){
                BTree p1, p2;
                p1 = (BTree)malloc(sizeof(bTree));
                p2 = (BTree)malloc(sizeof(bTree));
                int mid = t->keynum / 2;
                tmp = t->key[mid];
                init(p1);
                init(p2);
                for (int j = 0; j < mid;j++){
                    p1->key[j] = t->key[j];
                    p1->keynum++;
                }
                p1->parent = t;
                for (int j = mid + 1; j < t->keynum;j++){
                    p2->key[j] = t->key[j];
                    p2->keynum++;
                }
                p2->parent = t;
                for (int j = 0; j < t->keynum; j++)
                {
                    t->key[j] = 0;
                }
                t->key[0] = tmp;
                t->ptr[0] = p1;
                t->ptr[1] = p2;

            }
            else{
                int mid = (t->keynum + 1) / 2;
                index = find(t->parent->key, t->key[mid], t->parent->keynum);
                for (int j = t->parent->keynum; j >= index;j--){
                    t->parent->key[j] = t->parent->key[j - 1];
                    t->parent->ptr[j] = t->parent->ptr[j - 1];
                }
                t->parent->key[index] = t->key[mid];
                BTree p1 = (BTree)malloc(sizeof(bTree));
                init(p1);
                t->parent->ptr[index] = p1;
                p1->parent = t->parent;
                for (int i = mid; i < t->keynum;i++){
                    p1->key[i - mid] = t->key[i];
                }
                int a[maxn];
                for (int i = 0; i < mid;i++){
                    a[i] = t->key[i];
                }
                for (int i = 0; i < t->keynum;i++){
                    t->key[i] = 0;
                }
                for (int i = 0; i < mid;i++){
                    t->key[i]=a[i];
                }
                t->keynum = mid;
            }
        }
        
    }
   
}
//首先一直二分往下 一直到叶子节点 然后看能不能放下


int find(int *a,int x,int len){
    for (int i = 0; i < len;i++){
        if(a[i]>=x)
            return i;
        
    }
    return len + 1;
}

void init(BTree t){
    t->keynum = 0;
        t->parent = NULL;
        for (int index = 0; index < maxn;index++){
            t->key[index] = 0;
            t->ptr[index] = NULL;
        }
}
