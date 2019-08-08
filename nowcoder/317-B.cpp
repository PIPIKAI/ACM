#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
ll cnt[5]={0};
ll ans=0;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        cnt[t]++;
    }
    int pre=0;
    for(ll i=0;i<=n;i++)
    {
        ll sum=0,id;
        for(ll j=0;j<5;j++)
        {
            if(cnt[j]!=0&&sum<abs(j-pre))
            {
                sum=abs(j-pre);
                id=j;
            }
        }
       /// cout<<sum<<endl;
        ans+=sum*sum;
        cnt[id]--;
        pre=id;
    }
    cout<<ans<<endl;
    return 0;
}
