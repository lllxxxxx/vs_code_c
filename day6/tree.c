
#include<malloc.h>
#include<stddef.h>
#include<stdio.h>

typedef int ElementType;
typedef struct TreeNode *Ptr;
typedef struct TreeNode TreeNode;
// struct TreeNode{
//     ElementType Element;
//     PtrToNode FirstChild;
//     PtrToNode NextSibling;
// };
//链表形式
void xian(Ptr p);
Ptr CreateTree();
//二叉树
struct TreeNode{
    ElementType Element;
    Ptr right;
    Ptr left;
};

int main(void){
    Ptr p= CreateTree();
    
    xian(p);
    return 0;
}



Ptr CreateTree(){
        int data;
        scanf("%d", &data);
        if(data==-1){
            return NULL;
        }else{
            Ptr t=(Ptr)malloc(sizeof(TreeNode));
            
            t->Element = data;
            printf("输入%d的左子树", data);
            t->left = CreateTree();
            printf("输入%d的右子树", data);
            t->right= CreateTree();
            return t;
        }
    
    
}

//先序  先输出根节点
void xian(Ptr p){
    if(p==NULL){
        // printf("空指针");
        return;
    }else{
        printf("%d", p->Element);
        xian(p->left);
        xian(p->right);
    }
}
