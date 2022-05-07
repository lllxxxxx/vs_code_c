/*
 * @Author: lllxxx
 * @Date: 2022-03-24 19:35:00
 * @version: 1.0.0
 * @LastEditTime: 2022-04-13 23:02:23
 * @Description: 
 */
#include<stdio.h>

int main(void){

    union NUM{
        int a;
        char b;
    } num;
    num.a = 0x12345678;
    if(num.b==0x12){
        printf("大端\n");
    }
    else{
        printf("小端\n");
    }
    printf("num.b=0x%X\n", num.b);
    printf("num.a=0x%X\n", num.a);
    return 0;
}


int c(){
    return 0;
}