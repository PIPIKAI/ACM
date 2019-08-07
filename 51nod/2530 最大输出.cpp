#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
ll n,m,k;
ll ans,a[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    k++;
    sort(a,a+n);
    ll s1=a[n-1],s2=a[n-2];
    ll p=m%k,q=m/k;
    ans+=q*(s1*(k-1)+s2);
    ans+=p*s1;
    cout<<ans<<endl;
    return 0;
}
