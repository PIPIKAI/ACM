#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[105][105];
#define inf 1e7
struct node
{
    int w;
    int v;
};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,m,k,s;
	while(cin>>n>>m>>k>>s)
    {
        node f[105];
        int minn=inf;
       memset(dp,0,sizeof(dp));
       for(int i=0;i<k;i++)
           cin>>f[i].w>>f[i].v;
        for(int i=0;i<k;i++)
       {
           for(int j=f[i].v;j<=m;j++)
           {
               for(int c=1;c<=s;c++)
               {
                   dp[j][c]=max(dp[j][c],dp[j-f[i].v][c-1]+f[i].w);
                   if(dp[j][c]>=n&&minn>j)
                    minn=j;
               }
           }
       }
       if(minn==inf)
        cout<<"-1"<<endl;
       else
        cout<<m-minn<<endl;
    }
   return 0;
}

