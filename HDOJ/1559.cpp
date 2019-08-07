#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,y;
int f[1001][1001];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int T_T,ans;
	cin>>T_T;
	while(T_T--)
    {
        ans=0;
        memset(f,0,sizeof f);
        cin>>n>>m>>x>>y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            cin>>f[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                f[i][j]=f[i][j]-f[i-1][j-1]+f[i-1][j]+f[i][j-1];
            }
        for(int i=1;i<=n-x;i++)
        {
            for(int j=1;j<=m-y;j++)
            {
                int a=i+x-1;
                int b=j+y-1;
                int ss=f[a][b]+f[i-1][j-1]-f[a][j-1]-f[i-1][b];
                ans=max(ss,ans);
            }
        }
        cout<<ans<<endl;
    }
   return 0;
}
