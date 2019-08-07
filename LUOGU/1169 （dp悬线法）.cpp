#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7
#define mfor(i,a,b)  for(int i=a;i<=b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=2007;
int n,m,ans1,ans2;
int f[maxn][maxn];
int ll[maxn][maxn];///从（i，j)能到达最左的位置
int rr[maxn][maxn];///........最右..
int up[maxn][maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>f[i][j];
            ll[i][j]=rr[i][j]=j;
            up[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(f[i][j] ^ f[i][j-1] ){
                ll[i][j]=ll[i][j-1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=1;j--){
            if(f[i][j] ^ f[i][j+1] ){
                rr[i][j]=rr[i][j+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1&&f[i][j]!=f[i-1][j] ){
                ll[i][j]=max(ll[i][j],ll[i-1][j]);
                rr[i][j]=min(rr[i][j],rr[i-1][j]);
                up[i][j]=up[i-1][j]+1;
            }
            int a=rr[i][j]-ll[i][j]+1;
            int b=min(a,up[i][j]);
            ans1=max(ans1,b*b);
            ans2=max(ans2,up[i][j]*a);
        }
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
