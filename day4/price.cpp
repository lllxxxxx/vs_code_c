#include<iostream>
#include<cstdio>
using namespace std;
double d1,c,d2,p,ans=1e6,cn[10][2];
int n;
void get(int x,double s,double m)
{
	if(s<0 || s>c)
		return ;
	if(x==n+1)
	{
		ans=min(ans,m);
		return ;
	}
	for(int i=x;i<=n+1 && (cn[i][0]-cn[x][0])/d2<=c;i++)
		if((cn[i][0]-cn[x][0])/d2<=s)
			get(x+1,s-(cn[x+1][0]-cn[x][0])/d2,m);
		else
			get(x+1,(cn[i][0]-cn[x][0])/d2-(cn[x+1][0]-cn[x][0])/d2,m+((cn[i][0]-cn[x][0])/d2-s)*cn[x][1]);
	get(x+1,c-(cn[x+1][0]-cn[x][0])/d2,m+(c-s)*cn[x][1]);
	
}
int main()
{
	cin>>d1>>c>>d2>>p>>n;
	for(int i=1;i<=n;i++)
		cin>>cn[i][0]>>cn[i][1];
	cn[0][1]=p,cn[n+1][0]=d1;//初始化
	get(0,0,0);//从起点开始搜索
	if(ans==1e6)
		cout<<"No Solution";
	else
		printf("%.2lf",ans);
	return 0;
}