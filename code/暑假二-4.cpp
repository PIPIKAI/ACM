#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;
typedef long long ll;
using namespace std;
ll h[800005];
int vis[80000];
ll n,s,flag=0;
void dfs(int step,int sum)
{
    if(flag)
        return ;
    if(sum==s)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                cout<<h[i]<<" ";
        }
        flag=1;
        return ;
    }
    if(sum>s)
        return ;
    for(int i=step;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            if(sum+h[i]<=s)
            dfs(i,sum+h[i]);
            vis[i]=0;
        }
    }

}
int main()
{
    int aa=0;
       scanf("%lld%lld",&n,&s);
            memset(h,0,sizeof h);
            memset(vis,0,sizeof vis);
            for(ll i=1;i<=n;i++)
            {
                scanf("%d",h+i);
                aa+=h[i];
            }
            if(aa<s)
                return cout<<"No Solution!"<<endl,0;
            if(aa==s)
                {
                     for(int i=1;i<=n;i++)
                    {
                            cout<<h[i]<<" ";
                    }
                    cout<<endl;
                    return 0;
                }
            dfs(1,0);
            if(!flag)
                cout<<"No Solution!"<<endl;
    return 0;
}
