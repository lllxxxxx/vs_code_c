#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

#define LeftChild(i) (2 * (i) + 1)

//插入

void InsertSort(ElementType A[],int n){
    int j, p;
    ElementType tmp;
    for (p = 1; p < n;p++){
        tmp = A[p];
        for (j = p; j > 0 && A[j - 1] > tmp;j--){
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}


//希尔
void ShellSort(ElementType a[],int n){
    int i, j, in;
    ElementType tmp;
    for (in = n / 2; in > 0;in/=2){
        for (i = in; i < n;i++){
            tmp = a[i];
            for (j = i; j >= in;j-=in){
                if(tmp<a[j-in])
                    a[j] = a[j - in];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}


//堆
void percDown(ElementType a[],int i,int n){
    int child;
    ElementType tmp;
    for (tmp = a[i]; LeftChile(i) < n;i=child){
        child = LeftChild(i);
        if(child!=n-1&&a[child+1]>a[child]){
            child++;
        }
        if(tmp<a[child]){
            a[i] = a[child];
        }
        else{
            break;
        }
    }
    a[i] = tmp;
}

void HeapSort(ElementType a[],int n){
    for (int i = n / 2; i >= 0;i--){
        perDown(a, i, n);
    }
    for (int i = n - 1; i > 0;i--){
        swap(&a[0], &a[i]);
        perDown(a, 0, i);
    }
}