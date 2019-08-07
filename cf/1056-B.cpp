#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    ll ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((i*i+j*j)%m==0)
            {
                ans+=((n-i+m)/m)*((n-j+m)/m);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
