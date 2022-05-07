/*
 * @Author: your name
 * @Date: 2022-04-13 20:40:35
 * @LastEditTime: 2022-04-13 22:37:21
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE.
 * @FilePath: \vs_code_c\pa.c
 */
#include <stdio.h>

struct {
    int a;
    struct {
        int c;
    };
    struct {
        int v;
    } gen[8];
}g;

int main(){

    g.a= 5;
    printf("%d", g.c);
}

