#include<malloc.h>
#include<stddef.h>
#include<stdio.h>
#include"stack1.h"


struct Node{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack s){
    return s->Next==NULL;
}
Stack CreteStack(void){
    Stack s;
    s = (Stack)malloc(sizeof(struct Node));
    if(s==NULL){
        // FatalError("out of space!!!");
        printf("空指针");
    }
    else{
        s->Next = NULL;
        MakeEmpty(s);
        return s;
    }
}
void DisposeStack(Stack s){
    printf("???");
}
void MakeEmpty(Stack s){
    if(s==NULL){
        // Error("Must use CreateStack first!");
        printf("空指针");
    }
    else{
        while(!IsEmpty(s)){
            Pop(s);
        }
    }
}
void Push(ElementType x, Stack s){
    PtrToNode tmp;
    tmp = (PtrToNode)malloc(sizeof(struct Node));
    if(tmp==NULL){
        // FataError("error!!!");
        printf("空指针");
    }
    else{
        tmp->Element = x;
        tmp->Next = s->Next;
        s->Next = tmp;
    }
}
ElementType Top(Stack s){
    if(!IsEmpty(s)){
        return s->Next->Element;
    }
    // Error("Empty");
    printf("空");
    return 0;
}
void Pop(Stack s){
    PtrToNode first;
    if(IsEmpty(s)){
        // Error("empty");
        printf("空");
    }
    else{
        first = s->Next;
        s->Next = s->Next->Next;
        free(first);
    }
}
void PrintAll(Stack s){
    while(s->Next!=NULL){
        printf("%d", s->Next->Element);
        s->Next = s->Next->Next;
    }
}


