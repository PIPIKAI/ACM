#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
int n,k;
ll f[maxn],sum[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    sort(f,f+n);
    int mid=n/2;
    for(int i=0;i<n;i++){
       sum[i]=f[i]+sum[i-1];
    }
    for(int i=n-1;i>=mid;i--){
        if(i==mid){
            cout<<f[i]+k<<endl;
            break;
        }
        ll s=sum[i-1] - sum[mid-1];
        if(f[i] <= (s+k)/(i-mid) ){
            ll ans= (s+k+f[i])/(i-mid+1);
            cout<<ans<<endl;
            break;
        }

    }
    return 0;
}
