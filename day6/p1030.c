#include<stdio.h>
#include<string.h>
void gaga(char *c1, char *c2, int len1);
int len(char *a);
int main(void){
    int len1;
    char c1[8];
    char c2[8];
    gets(c1);
    gets(c2);
    len1 = len(c1);
    
    // printf("%d", len1);
    gaga(c1, c2, len1);
    return 0;
}
void gaga(char *c1,char *c2,int len1){
    if(len1<=1){
        if(c1[0]>='A'&&c1[0]<='Z'){
        printf("%c", c1[0]);
        }
    }else{
    char root = c2[len1 - 1];
    int index=0,alen1=0,alen2=0,i=0,j=0;
    char a1[8], a2[8],b1[8],b2[8];
    printf("%c", root);
    for (i = 0; i < len1;i++){
        if(c1[i]==root){
            index = i;
        }
    }
    for (j = 0; j < index;j++){
        a1[j] = c1[j];
    }
    for (j = index+1; j < len1;j++){
        a2[j-index-1] = c1[j];
    }
    alen1 = len(a1);
    alen2 = len(a2);
    for (j = 0; j < alen1;j++){
        b1[j] = c2[j];
    }
    for (j = alen1; j < alen1+alen2;j++){
        b2[j-alen1] = c2[j];
    }
   
    gaga(a1, b1, alen1);
    gaga(a2, b2, alen2);
    }
}

int len(char *a){
    int c = 0;
    for (int i = 0; i < 8;i++){
        if(a[i]>='A'&&a[i]<='Z'){
            c += 1;
        }
    }
    return c;
}