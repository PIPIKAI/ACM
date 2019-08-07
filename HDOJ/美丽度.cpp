#include<bits/stdc++.h>  
typedef long long ll;
using namespace std;
ll n,m,y;
const int mod=1e9+7;
const int maxn=1e6+8;
#define mem(x, y) memset(x,y,sizeof(x))
ll f[maxn];
ll o(ll n){
    return (1+n)*n/2;
}
int main()
{
    while(cin>>n){
        ll ans=0;
        for(ll i=1,t;i<=n;i++){
            cin>>t;
            ans= (ans+ o(n-i+1) %mod* t%mod * i %mod) %mod;
            //cout<<( (n-i+1)*(1+i)*(i-1+1)/2)<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
