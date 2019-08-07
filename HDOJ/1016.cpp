#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[25],n,vis[25],bi[100];
void biao()
{
    bi[1]=0;
    for(int i=2;i<=6;i++)
    {
        if(bi[i])
        {
            for(int j=2;i*j<=40;j++)
            bi[j*i]=0;
        }
    }
}
void dfs(int step)
{
    if(step==n)
    {
        if(bi[1+f[step]])
        {
            cout<<1;
            for(int i=2;i<=n;i++)
            cout<<" "<<f[i];
            cout<<endl;
        }

        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(vis[i]==0&&bi[i+f[step]])
        {
                f[step+1]=i;
                vis[i]=1;
                dfs(step+1);
                vis[i]=0;


        }
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   memset(bi,1,sizeof(bi));
   biao();
   int g=0;
	while(cin>>n)
    {
        g++;
        cout<<"Case"<<" "<<g<<":"<<endl;
        memset(vis,0,sizeof(vis));
        f[1]=1;
        dfs(1);
        cout<<endl;
    }
   return 0;
}
