#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2e9+7
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y,d,ans=inf;
        cin>>n>>x>>y>>d;
        if(abs(y-x)%d==0)
        {
            ans=min(ans,(abs(y-x))/d);
        }
        else if((y-1)%d==0||(n-y)%d==0)
        {
            if((y-1)%d==0)
            ans=min(ans,abs(x-1)/d+1+(y-1)/d );
            if((n-y)%d==0)
            ans=min(ans,abs(n-x)/d+(n-y)/d+1 );
        }
        if(ans==inf)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}