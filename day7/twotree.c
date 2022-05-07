#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;
struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree t){
    if(t!=NULL){
        MakeEmpty(t->Left);
        MakeEmpty(t->Right);
        free(t);
    }
    return NULL;
}

Position Find(ElementType x,SearchTree t){
    if(t==NULL){
        return NULL;
    }
    if(x<t->Element){
        return Find(x, t->Left);
    }else{
        if(x>t->Element){
            return Find(x, t->Right);
        }
        else{
            return t;
        }
    }
}

Position FindMIn(SearchTree t){
    if(t==NULL){
        return NULL;
    }
    else{
        if(t->Left==NULL){
            return t;
        }
        else{
            return FindMIn(t->Left);
        }
    }
}

Position FindMax(SearchTree t){
    if(t!=NULL){
        while(t->Right!=NULL){
            t = t->Right;
        }
        return t;
    }
    return NULL;
}

SearchTree Insert(ElementType x,SearchTree t){
    if(t==NULL){
        t = (SearchTree)malloc(sizeof(struct TreeNode));
        if(t==NULL){
            // FataError();
            // return;
            printf("zzz");
        }
        else{
            t->Element = x;
            t->Left = NULL;
            t->Right = NULL;
        }
    }
    else{
        if(x<t->Element){
            t->Left = Insert(x, t->Left);
        }
        else{
            if(x>t->Element){
                t->Right = Insert(x, t->Right);
            }
            
        }
        
    }
    return t;
}

SearchTree Delete(ElementType x,SearchTree t){
    Position tmp;
    if(t==NULL){
        // Error();
        // return;
    }
    else{
        if(x<t->Element){
            t->Left = Delete(x, t->Left);
        }
        else{
            if(x>t->Element){
                t->Right = Delete(x, t->Right);
            }
            else{
                if(t->Left&&t->Right){
                    tmp = FindMIn(t->Right);
                    t->Element = tmp->Element;
                    t->Right = Delete(t->Element, t->Right);
                }
                else{
                    tmp = t;
                    if(t->Left==NULL){
                        t = t->Right;
                    }
                    else{
                        if(t->Right==NULL){
                            t = t->Left;
                        }
                        
                    }
                    free(tmp);
                }
            }
        }
    }
    return t;
}


int main(){
    SearchTree p = NULL;
   
    p = MakeEmpty(p);
    p = Insert(5, p);
    p = Insert(8, p);
    p = Insert(1, p);
    p = Insert(3, p);
    p = Delete(8, p);
    printf("%d", p->Element);
    printf("%d", p->Right->Element);
}

