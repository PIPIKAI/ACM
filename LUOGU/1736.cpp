#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define aa  2501
int rr()
{
    int x;scanf("%d",&x);return x;
}
int n,m,ans;
int f[aa][aa],z1[aa][aa],z2[aa][aa],a[aa][aa];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>f[i][j];
             if(f[i][j])
                a[i][j]=min(a[i-1][j-1],min(z1[i-1][j],z2[i][j-1]))+1;
            if(!f[i][j])
            {
                z1[i][j]=z1[i-1][j]+1;
                z2[i][j]=z2[i][j-1]+1;
            }
            ans=max(a[i][j],ans);
        }
    mem(a,0);
    mem(z1,0);
    mem(z2,0);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        {
            if(f[i][j])
                a[i][j]=min(a[i-1][j+1],min(z1[i-1][j],z2[i][j+1]))+1;
            if(!f[i][j])
            {
                z1[i][j]=z1[i-1][j]+1;
                z2[i][j]=z2[i][j+1]+1;
            }
            ans=max(a[i][j],ans);
        }
    cout<<ans<<endl;
    return 0;
}
