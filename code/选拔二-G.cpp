#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x,y;
}f[200144];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
ll qq(ll n, ll b)
{
    ll s=1;
    while(n--)
    {
        s=s*4;
        if(s>b)
            return -1;
    }
    return s;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        {
            cin>>f[i].x>>f[i].y;
        }
    sort(f,f+n,cmp);
    ll cnt=0,s=0;
        for(ll i=1;i<n;i++)
       {
            if(f[i].x!=f[i-1].x)
            {
                ll pp=qq(f[i].x-f[i-1].x,f[i-1].y);
                if(pp==-1)
                cnt=0;
                else
                cnt=f[i-1].y/pp;
                f[i].y+=cnt;
            }
            else
            {
                f[i].y+=f[i-1].y;
            }
        }
    ll ans=f[n-1].x;
    ll sum=f[n-1].y;
    while(sum!=0)
    {
        sum=(sum-1)/4;
        ans++;
    }
    cout<<ans<<endl;
   return 0;
}

