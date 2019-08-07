#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int d[305][305],dd[305][305],f[605]={0};
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>f[i],f[i+n]=f[i];

    for(int i=1;i<=2*n;i++)
    {
        f[i]+=f[i-1];
    }
    int ans1=inf,ans2=0;

    for(int i=(n<<1)-1;i>=1;i--)
    {
        for(int j=i+1;j<=i+n;j++)
        {
            d[i][j]=inf;
            for(int k=i;k<j;k++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+f[j]-f[i-1]);
                dd[i][j]=max(dd[i][j],dd[i][k]+dd[k+1][j]+f[j]-f[i-1]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans1=min(ans1,d[i][n+i-1]);
        ans2=max(ans2,dd[i][n+i-1]);
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
