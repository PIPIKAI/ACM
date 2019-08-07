#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=1e6+7;
ll f[maxn],k[maxn];
void ini()
{
    ll c=0,b=0;
    for(int i=1;i<maxn;i++){
        int t=i;
        while(t%5==0){
            t/=5;c++;
        }
        t=i;
        while(t%2==0){
            t/=2;b++;
        }
        f[i]=c;
        k[i]=b;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    ll n,r,p,q,t,ca=0;
    ini();
    cin>>t;
    while(t--){
        ca++;
        cin>>n>>r>>p>>q;
        cout<<"Case "<<ca<<": ";
        ll ans1= ( f[n]-f[r]-f[n-r] + q*(f[p]-f[p-1]) );
        ll ans2= ( k[n]-k[r]-k[n-r] + q*(k[p]-k[p-1]) );
        cout<<ans1<<endl;
    }
    return 0;
}
