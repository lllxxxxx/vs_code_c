#include"AVL.h"
#include<stdlib.h>
#include<stdio.h>

// #define MAX(x,y) x>y?x:y

static Position SingleRotLeft(Position k2);
static Position SingleRotRight(Position k2);
static Position DoubleRotLeft(Position k3);
static Position DoubleRotRight(Position k3);
int MAX(int a, int b);

struct AvlNode{
    ElementType Element;
    AvlTree left;
    AvlTree right;
    int height;
};

static int Height(Position p){
    if(p==NULL)
        return -1;
    else
        return p->height;
}

int MAX(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

Position Find(ElementType x, AvlTree t);
Position FindMin(AvlTree t);
Position FindMax(AvlTree t);
AvlTree Insert(ElementType x, AvlTree t){
    if(t==NULL){
        t = malloc(sizeof(struct AvlNode));
        if(t==NULL){
            printf("is NULL");
        }
        else{
            t->Element = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
    }
    else{
        if(x<t->Element){
            t->left = Insert(x, t->left);
            if((Height(t->left)-Height(t->right))==2){
                if(x<t->left->Element)
                    t = SingleRotLeft(t);
                else
                    t = DoubleRotLeft(t);
            }
        }
        else{
            if(x>t->Element){
                t->right = Insert(x, t->right);
                if(Height(t->right)-Height(t->left)==2){
                    if(x>t->right->Element)
                        t = SingleRotRight(t);
                    else
                        t = DoubleRotRight(t);
                }
            }
        }
    }
    t->height = MAX(Height(t->left), Height(t->right)) + 1;
    return t;
}
AvlTree Delete(ElementType x, AvlTree t);
ElementType Retrieve(Position p);

static Position SingleRotLeft(Position k2){
    Position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = MAX(Height(k2->left), Height(k2->right))+1;
    k1->height = MAX(Height(k1->left), k2->height) + 1;
    return k1;
}

static Position SingleRotRight(Position k2){
    Position k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = MAX(Height(k2->left), Height(k2->right))+1;
    k1->height = MAX(Height(k1->right), k2->height) + 1;
    return k1;
}

static Position DoubleRotLeft(Position k3){
    k3->left = SingleRotRight(k3->left);
    return SingleRotLeft(k3);
}

static Position DoubleRotRight(Position k3){
    k3->right = SingleRotLeft(k3->right);
    return SingleRotRight(k3);
}


int main(){
    AvlTree t = malloc(sizeof(struct AvlNode));
    t->Element = 9;
    t->height = 0;
    t->left = t->right = NULL;
    t=Insert(10, t);
    t=Insert(11, t);
    // t=Insert(5, t);
    printf("zz");
}