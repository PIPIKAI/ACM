#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
ll f[1050][1005]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        ll ans=0;
        cin>>n>>m;
        if(m&1)
        {
            ans=n*(m-1)+n-2;
        }
        else
        {
            ans=n*(m-1)-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
