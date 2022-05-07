#include<stdio.h>
#define min(x,y) x>y?y:x
void dfs(int index, double curOil, double free);
static double ans=9999;
int n;
double np1[7]={0};
double np2[7]={0};
double d1,d2,c,p;
//d1总距离  d2每升汽油的距离  c容量        p价格  n数量
int main(void){
    double d3, p1;
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&d3,&p1);
        np1[i]=d3;
        np2[i]=p1;
    }
    np1[n + 1] = d1;
    np2[0] = p;
    //--------数据输入完毕-------
    dfs(0, 0, 0);
    if(ans==9999){
        printf("No Solution");
    }else{
    printf("%.2lf", ans);
    }
    return 0;
}

void dfs(int index,double curOil,double free){//参数 index  总花费  油量
    // if(curOil==0&&index!=n+1&&index!=0){
    //     printf("No Solution");
    //     return; //没油了并且没到最后一站
    // }

    if(curOil>c||curOil<0){
        return;                 //不正常油量
    }
    if(index==n+1){
        ans = min(ans, free);   //到了最后一站更新数据
        return;
    }
   

    //不加满有几种情况
    //  1.不加 油够  2.加到刚好到下一站
    //什么时候加 什么时候不加  不加说明油能到下一站
    //距离是np1[index+1]-np1[index]
    for (int i = index; i <= n + 1 && (np1[i] - np1[index]) / d2 < c;i++)
    {
        if ((np1[i] - np1[index]) < (curOil * d2))
        {
            dfs(index + 1, curOil - (np1[index + 1] - np1[index]) / d2, free);
        }
        else
        {
            dfs(index + 1, (np1[i]-np1[index])/d2-(np1[index+1]-np1[index])/d2, free + ((np1[i]-np1[index])/d2-curOil )* np2[index]);
        }
    }
    dfs(index + 1, c - (np1[index + 1] - np1[index] )/ d2, free + (c - curOil) * np2[index]);//油量加满
}




//2-2-2
//----3