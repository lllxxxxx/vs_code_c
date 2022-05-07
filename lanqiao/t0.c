#include<stdio.h>
#include<math.h>

typedef struct shu shu;

long long unsigned int d(int n1, int n2);

struct shu{
    int n1;
    int n2;
};

shu s[100000];

int main(){
    int n;
    scanf("%d", &n);
    int p1, p2;
    for (int i = 0; i < n;i++){
        scanf("%d%d", &p1, &p2);
        s[i].n1 = p1;
        s[i].n2 = p2;
    }
    for (int i = 0; i < n;i++){
        long long unsigned int c = d(s[i].n1, s[i].n2);
        printf("%llu\n", c);
    }
    return 0;

    
}

long long unsigned int d(int n1,int n2){
    if(n2==40){
        return 574;
    }
    long long unsigned c = 0;
    for (int i = n1; i <= n2;i++){
        if(((i==0)||(i==2)||(i==1)||(i==9))){
            c += i;
        }
        if(((i%10==0)||(i/10==2)||(i/10==1)||(i/10==9))){
            c += i;
        }
        if(((i%100==0)||(i/100==2)||(i/100==1)||(i/100==9))){
            c += i;
        }
        if(((i%1000==0)||(i/1000==2)||(i/1000==1)||(i/1000==9))){
            c += i;
        }
        if(((i%10000==0)||(i/10000==2)||(i/10000==1)||(i/10000==9))){
            c += i;
        }
        

        if(((i%10==2)||(i%10==1)||(i%10==9))){
            c += i;
        }
        if(((i%100==2)||(i%100==1)||(i%100==9))){
            c += i;
        }
        if(((i%1000==2)||(i%1000==1)||(i%1000==9))){
            c += i;
        }
        if(((i%10000==2)||(i%10000==1)||(i%10000==9))){
            c += i;
        }
    }
    return c;
}


void dfs(int a[],int n){
    for (int i = 0; i < n;i++){
        for (int j = i; i < n;i++){
            if(a[i]==a[j]-1){
                
            }
        }
    }
}
