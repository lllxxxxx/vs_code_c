#include<bits/stdc++.h>
using namespace std;
int edge[1000][1000];
//为了方便优先访问编号小的节点，这里使用邻接矩阵来存边
//如果使用vector来存图，那还需要对每个节点连接的边进行排序
int ans[1000000];
int degree[1000];//用于储存每个点的度，以求起点
int p=0;
void dfs(int now)
{
    for(int i=1;i<=1000;i++)//顺序寻找可访问的边，优先找编号小的节点
    {
        if(edge[now][i])//若这条边尚未访问过
        {
            edge[now][i]--;//已访问过的边要删去，防止重复访问
            edge[i][now]--;//有向图的话请删去这一行
            dfs(i);
        }
    }
    ans[++p]=now;//将访问的节点储存进答案数组
    //由于递归的特性，这里储存的是逆序过程
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;//边的个数
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a][b]++;
        edge[b][a]++;//有向图的话删去这行
        degree[a]++,degree[b]++;//两个点的度都+1
    }
    int start=0;
    for(int i=1;i<=1000;i++)
    {
        if(degree[i]%2)//如果找到奇数点
        {
            start=i;//那这个奇数点就作为起点，由于顺序遍历，这个起点编号必定最小
            break;
        }
    }
    if(!start)//如果还没找到奇数点，说明是欧拉回路
    {
        for(int i=1;i<=1000;i++)
            if(degree[i])//寻找最小的有度的点即可
            {
                start=i;
                break;
            }
    }
    dfs(start);//dfs寻找欧拉路
    for(int i=p;i>=1;i--)
        cout<<ans[i];//输出给定的欧拉路
}