#define MAX(x,y) x>y?x:y
#include<stdio.h>

int main(void){
    int a, b, c;
    a = 2;
    b = 3;
    c = MAX(a, b);
    printf("%d", c);
}