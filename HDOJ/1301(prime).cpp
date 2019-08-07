#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7
int f[28][28],n;
void prime()
{
    int ans=0,vis[28]={0};
    int dis[28]={0};
    vis[0]=1;
    for(int i=0;i<n;i++)
        dis[i]=f[0][i];
    for(int i=0;i<n-1;i++)
    {
        int k=0,min=inf;
        for(int j=0;j<n;j++)
        {
            if(min>dis[j]&&!vis[j])
                min=dis[j],k=j;
        }
        ans+=min;
        //cout<<min<<endl;
        vis[k]=1;
        for(int j=0;j<n;j++)
        {
            if(dis[j]>f[k][j]&&!vis[j])
                dis[j]=f[k][j];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    while(cin>>n,n)
    {
        memset(f,inf,sizeof(f));
        for(int i=0;i<n-1;i++)
        {
            char c;
            int k,t,s;
            cin>>c>>k;
            t=c-'A';
                for(int j=0;j<k;j++)
                {
                    cin>>c>>s;
                    if(f[t][c-'A']>s)
                    {
                        f[t][c-'A']=f[c-'A'][t]=s;
                    }
                }
        }
        prime();
    }
    return 0;
}
