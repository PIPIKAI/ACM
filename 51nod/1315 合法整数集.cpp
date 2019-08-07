#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define ffr(i,a,b)  for(int i=a;i<b;i++)
ll n,x,t,cnt;
ll f[33],ans=2e9,inix[33];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>x;
    t=x;
    cnt=0;
    while(t)
    {
        inix[cnt++]+=(t&1);
        t>>=1;
    }
    ffr(i,0,n)
    {
        cin>>t;
        if( (t|x) >x)
            continue;
        cnt=0;
        while(t)
        {
            f[cnt++]+= (t&1);
            t>>=1;
        }
    }
    ffr(i,0,33)
    {
        if(inix[i]&&!f[i])
        {
            ans=0;
            break;
        }
        if(f[i])
            ans=min(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}
