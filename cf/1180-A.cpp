#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    ll ans=1,tp=0;
    for(int i=2;i<=n;i++){
        ans=ans+tp+4;
        tp+=4;
    }
    cout<<ans<<endl;
    return 0;
}
