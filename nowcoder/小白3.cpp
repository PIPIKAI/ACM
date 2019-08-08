#include<stdio.h>
using namespace std;
typedef long long ll;
int vis[1000010],n;
int w[1000020]={0};
int max(int a,int b)
{
    return a>b?a:b;
}
int find(int  x)
{
    while(vis[x]!=x)
        x=vis[x];
    return x;
}
int merge(int  a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return w[a];
    else
    {
        if(a>b)
        {
            vis[a]=b;
        }
        else
        {
            vis[b]=a;
        }
        int t=w[a]+w[b];
        w[a]=w[b]=t;
        return t;
    }

}
int main()
{
    int ans=0;
    scanf("%d",&n);
    if(n==1)
        printf("1\n");
    else
    {
        for(int i=1;i<=n;i++)
        vis[i]=i,w[i]=1;
    for(int i=1;i<n;i++)
    {
       int x,y;
        scanf("%d%d",&x,&y);
         ans=max(ans,merge(x,y));
    }
    printf("%d\n",ans);
    }

   return 0;
}

