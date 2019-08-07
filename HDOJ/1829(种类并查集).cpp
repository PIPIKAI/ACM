#include<bits/stdc++.h>
#define pt printf
using namespace std;
int f[2005],h[2005];
int n,m,flag;
void ini()
{
    for(int i=0;i<=n;i++)
        f[i]=i,h[i]=0;
}
int find(int x)
{
   if(x==f[x])
    return f[x];
    int t=find(f[x]);
    h[x]=(h[x]+h[f[x]])%2;
    f[x]=t;
    return f[x];
}
void merg(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b)
    {
        if(h[x]==h[y])
        flag=1;
        return ;
    }
    f[a]=b;
    h[a]=(h[x]-h[y]+3)%2;
}
int main()
{
    int T;
    scanf("%d",&T);
        int ca=0;
        while(ca<T)
        {
            ca++;
            flag=0;
            scanf("%d%d",&n,&m);
            ini();
            for(int i=0;i<m;i++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if(!flag)
                {
                    merg(x,y);
                }
            }
             printf("Scenario #%d:\n",ca);
        if(flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
        }
    return 0;
}
