#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,ans=0;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    while(n)
    {
        ans=max(ans,n%10);
        n/=10;
    }
    cout<<ans<<endl;
    return 0;
}
