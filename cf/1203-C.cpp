#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=4e5+7;
int n,k;
ll gcd(ll a,ll b) {while(b^=a^=b^=a%=b);return a;}
ll f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>f[0];
    ll a=f[0];
    for(int i=1;i<n;i++){
        cin>>f[i];
        a=gcd(f[i],a);
    }
    ll ans=0;
    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            if(i*i==a){
                ans++;
            }else{
                ans+=2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
