#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=5005;
int n,m;
ll a[maxn],sum[maxn],dp[maxn][maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    ll t=0,;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=0){
            t+=a[i];
            a[i-1]>=0 ? a[i]=i-1 : a[i]=
        }
        else{

        }
    }
    if(m>=n){
        cout<<sum[n]<<endl;
    }
    else{

    }
    return 0;
}
