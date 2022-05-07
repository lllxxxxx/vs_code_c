
#include<stdio.h>
int main(){
    int a = 1, b = 1, c = 0;
    int d = (a = b + c);
    if (a=b+c){
        printf("dd\n");
    }else{
        printf("dddddddd\n");
    }
    printf("%d", d);
}
