#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int mod=63611646;
int n,m;
ll f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    sort(f,f+n);
    sort(k,k+n);
    for(int i=1;i<=n;i++){
        l[i-1]=i*(n-i+1);
    }
    sort(l,l+n);
    for(int i=0;i<n;i++){
        ans=(ans+l[n-i-1]*k[i]*f[i])%mod;
    }

    return 0;
}
