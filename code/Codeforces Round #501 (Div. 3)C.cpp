#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100005];
bool cmp(ll a,ll b)
{
    return a>b;
}
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        ll sum=0,ans=0,flag=0;
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            sum+=x;
            f[i]=x-y;
        }
        sort(f,f+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(m>=sum)
            {
                flag=1;break;
            }
            sum-=f[i];
            ans++;
        }
        if(m>=sum)
            flag=1;
        if(flag)
        cout<<ans<<endl;
        else
        cout<<"-1"<<endl;
    }
    return 0;
}
