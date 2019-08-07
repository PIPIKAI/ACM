#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x,y;
    ll k;
}f[100021];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,n;
        cin>>x>>y>>n;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>f[i].x>>f[i].y;
            f[i].k=min(min(f[i].x,f[i].y),min(abs(f[i].x-x),abs(f[i].y-y)));
            ans+=f[i].k;
        }
        cout<<ans<<endl;
    }
   return 0;
}

