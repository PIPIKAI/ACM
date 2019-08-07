#include<bits/stdc++.h>
using namespace std;
int f[150000];
int find(int x)
{
    while(f[x]!=x)
        x=f[x];
    return x;
}
void sunion(int x,int y)
{
    int f1=find(x);
    int f2=find(y);
    if(f1<f2)
        f[f2]=f1;
    if(f1>f2)
        f[f1]=f2;
}
int main()
{
    int n,m,ans;
    while(cin>>n)
    {
        if(n==0)
            break;
        cin>>m;
        ans=0;
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=0;i<m;i++)
        {
            int x,y,ans=n;
            scanf("%d%d",&x,&y);
            sunion(x,y);
        }
         for(int i=1;i<=n;i++)
            if(f[i]==i)
                ans++;
        printf("%d\n",ans-1);

    }
    return 0;
}
