#include<cstdio>
#include<algorithm>
const int N=1000010;
int n,i,x,a[N],b[N],vis[N];
int main(){
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
  for(i=x=1;i<=n;i++){
    printf("%d ",x);
    vis[x]=1;
    int A=a[x],B=b[x];
    if(a[A]!=B&&b[A]!=B)std::swap(A,B);
    if(vis[A])std::swap(A,B);
    x=A;
  }
