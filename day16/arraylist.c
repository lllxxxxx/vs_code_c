#include<stdio.h>
#include<stdlib.h>

#define maxSize 100

typedef int ElementType;
typedef struct{
    int data[maxSize];
    int len;
} arrayList;

int locateElem(arrayList list,ElementType x){
    for (int i = 0; i < list.len;i++){
        if(list.data[i]==x)
            return i;
    }
    return -1;
}

void insertElem(arrayList *list,ElementType x,int i){
    if(i<0||i>=list->len)
        printf("error");
    for (int j = list->len; j>=i;j--){
        list->data[j] = list->data[j - 1];
    }
    list->data[i] = x;
    list->len++;
}

void deleteElem(arrayList *list,int i){
    if(i<0||i>=list->len)
        printf("error");
    for (int j = i; j < list->len;j++)
        list->data[j] = list->data[j + 1];
    list->len--;
}

void reserve(arrayList *list){
    if(list->len){
        for (int i = 0; i < list->len;i++){
            int p = list->data[i];
            list->data[i] = list->data[list->len - i - 1];
            list->data[list->len - i - 1] = p;
        }
    }
}