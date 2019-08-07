#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n;
ll solve(ll n)
{
    ll re=0;
    for(ll i=2;i*i<=n;i++){
        ll k=i*(n/i-1);
        re+= k;
        if(n/i>sqrt(n)){
            ll p=sqrt(n)+1,q=n/i;
            re+= (p+q)*(q-p+1)/2;
        }
    }
    return re;
}
int main()
{
    std::ios::sync_with_stdio(false);
    ll t,ca=0;
    cin>>t;
    while(t--)
    {
        ca++;
        cin>>n;
        cout<<"Case "<<ca<<": ";

        cout<<solve(n)<<endl;
    }
    return 0;
}
