#include<stdio.h>
// #include<stddef.h>
int bound(int *c, int x, int bolean,int len);
int miss[10000];
int cop1[10000], cop2[10000];
int main(void){
    int c;
    int n = 1;
    int len1 = 1, len2 = 1;
    do{
        scanf("%d", &c);
        miss[n++] = c;
    }while( getchar() != '\n');
    cop1[1] = miss[1];
    cop2[1] = miss[1];
    for (int i = 2; i < n;i++){
        if(miss[i]<=cop1[len1]){
            cop1[++len1] = miss[i];
        }else{
            int p = bound(cop1, miss[i], 0, len1);
            cop1[p] = miss[i];
        }
        if(miss[i]>cop2[len2]){
            cop2[++len2] = miss[i];
        }else{
            int p1 = bound(cop2, miss[i], 0, len2);
            cop2[p1] = miss[i];
        }
    }
    printf("%d\n%d", len1, len2);
    return 0;
}


int bound(int *c,int x,int bolean,int len){
    int i=1;
    
    if(bolean==1){
        while(i<=len){
           if(*(c+i)>=x){
               return i;
           }
           i++;
        }
        return -1;
    }else{
         while(i<=len){
           if(*(c+i)<x){
               return i;
           }
           i++;
        }
        return 1;
    }
}