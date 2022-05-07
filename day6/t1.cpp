#include<iostream>
#include<cstring>

using namespace std;

char pre[10];//后序遍历
char mid[10];//前序遍历
int num[300];//字母对应的数字
char let[10];//数字对应的字母

struct node//结点
{
    int key;
    node * p=NULL;//父节点
    node * left=NULL;//左子
    node * right=NULL;//右子
};
typedef struct node * bNode;//结点指针

bNode tree_insert(bNode tree_root,int nkey)//二叉搜索树插入函数
{
    bNode z=new node,y=NULL,x=tree_root;
    z->key=nkey;
    while(x!=NULL)
    {
        y=x;
        if(nkey<x->key)x=x->left;
        else x=x->right;
    }
    z->p=y;
    if(y==NULL)tree_root=z;
    else if(nkey<y->key)y->left=z;
    else y->right=z;
    
    return tree_root;
}

void tree_preorder(bNode k)//前序遍历输出
{
    if(k==NULL)return;
    cout<<let[k->key];//key对应的字母
    tree_preorder(k->left);
    tree_preorder(k->right);
}

int main()
{
    bNode t1=NULL;
    cin>>mid>>pre;
    for(int i=0;mid[i]!='\0';i++)//建立字母与标号的双向联系
    {
        num[mid[i]]=i;
        let[i]=mid[i];
    }
    for(int i=strlen(pre)-1;i>=0;i--)//按颠倒顺序插入
    {
        t1=tree_insert(t1,num[pre[i]]);
    }
    tree_preorder(t1);
    return 0;
}
