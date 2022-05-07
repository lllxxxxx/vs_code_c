#include<stdio.h>
#include<math.h>
void print(int index, int tol);
char tree[1500];

int main(void){
    int n;
    int tol;
    int di = 2;
    scanf("%d", &n);
    tol = pow(di, n);
    getchar();
    gets(tree+1);
    print(1, tol);
    return 0;
    // scanf("%[^\n]",tree);
}

void print(int index,int tol){
    if(tol-index<0){
        return;
    }
    int c = (tol - index + 1) / 2;
    print(index,index+c-1);
    
    print(tol-c+1, tol);
    int c1 = 0, c0 = 0;
    for (int i = index; i <= tol;i++){
        if(tree[i]=='1'){
            c1 += 1;
        }
        if(tree[i]=='0'){
            c0 += 1;
        }
    }
    if(c1==tol-index+1){
        printf("I");
    }else{
        if(c0==tol-index+1){
            printf("B");
        }else{
            printf("F");
        }
    }
}