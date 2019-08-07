#include<bits/stdc++.h>
using namespace std;
vector <int > f[5008];
int n,p,link[5005];
bool vis[5500];
bool dfs(int x)
{
    for(int j=0;j<f[x].size();j++)
    {
        int i=f[x][j];
        if(!vis[i])
        {
            vis[i]=1;
            if(link[i]==-1||dfs(link[i]))
            {
                link[j]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t,sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        memset(f,0,sizeof f);
        memset(vis,0,sizeof vis);
        memset(link,-1,sizeof link);
        cin>>n;
        p=(n*3)/2;
        for(int i=1;i<=p;i++)
        {
            int a,b;
            cin>>a>>b;
            f[a].push_back(b);
            f[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            if(dfs(i))
                sum++;
        }
        cout<<sum/2<<endl;
    }
    return 0;
}
