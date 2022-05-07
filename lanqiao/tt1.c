#include<stdio.h>
#include<unistd.h>

int main(){
    static int x, x1;
    static int y, y1;
    while(1){
        x1 = !x && y;
        y1 = !x && !y;
        printf("x=%d", x);
        printf("y=%d", y);
        x = x1;
        y = y1;
        putchar('\n');
        sleep(1);
    }
}