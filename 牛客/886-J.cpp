#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e3+7;
int n,m;
int f[maxn][maxn],gf[maxn][maxn],gd[maxn];
int d[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int t,cas=0;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=gf[i][j]=d[i]=gd[i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>f[i][j];
                gf[i][j]=gf[i][j-1]+f[i][j];
            }
        }
        for(int j=1;j<=m;j++){
                cin>>d[j];
                gd[j]=gd[j-1]+d[j];
        }

        cout<<"Case #"<<++cas<<": ";


    }
    return 0;
}
