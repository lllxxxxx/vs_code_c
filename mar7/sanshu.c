#include<stdio.h>
// using namespace std;


int a[100000],b[100000],c[100000];

int main()
{ 
  int ans=0;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(b[j]>a[i]){
        for(int k=0;k<n;k++){
          if(b[j]<c[k]){
            ans++;
          }
        }
      }
    }
  }
  printf("%d", ans);
  return 0;
}



