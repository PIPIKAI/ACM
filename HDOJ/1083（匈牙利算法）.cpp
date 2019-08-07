#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[500],f[500][500];
int t,p,n;
int  link[500];
bool dfs(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(f[x][i]==1 && !vis[i])
        {
            vis[i]=1;
            if(link[i]==-1 ||dfs(link[i]))
            {
                link[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--)
    {
        memset(f,0,sizeof f);
        memset(link,-1,sizeof link);
        int sum=0;
        cin>>p>>n;
        for(int i=1;i<=p;i++)
        {
            int c,cc;
            cin>>c;
            for(int j=0;j<c;j++)
            {
                cin>>cc;
                f[i][cc]=1;
            }
        }

        for(int i=1;i<=p;i++)
        {
            memset(vis,0,sizeof vis);
            if(dfs(i))
                sum++;
        }
        if(sum==p)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
   return 0;
}
