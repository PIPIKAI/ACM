#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
ll n,m,k,a,b,c;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll ans=-1;
        cin>>n>>m>>k>>a>>b>>c;
        ll man,fman;
        for(ll i=0;i<=k;i++){
            ll sum=0;
            sum+=i*c;
            man=n+k-i;
            fman=m+k-i;

            ll z1=(man/3)*b,z2=(man/2)*a;
            man%3 ? z1+=min(a,b) :1;
            man%2 ? z2+=min(a,b) :1;
            sum=sum+ min(z1,z2);

            z1=(fman/3)*b,z2=(fman/2)*a;
            fman%3 ? z1+=min(a,b):1;
            fman%2 ? z2+=min(a,b):1;
            sum=sum+ min(z1,z2);
            ans= ans==-1 ? sum : min(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}
