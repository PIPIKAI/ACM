#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<ll > f[200005];
int vis[200008];
void ini()
{
    for(int i=0;i<=n;i++)
        vis[i]=i;
}
struct nn
{
    ll w,i;
}maxn;
void add(ll a,ll b)
{
    f[a].push_back(b);
    f[b].push_back(a);
    nn z,zz;
    z.w=f[a].size();z.i=a;
    zz.w=f[b].size();zz.i=b;
    if(z.w<zz.w) z .w= zz.w,z.i=zz.i;
    if(z.w >maxn.w) maxn=z;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        ini();
        maxn.w=0;
        cin>>n>>m>>k;
        for(int i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            add(a,b);
        }
        ll dian=0;
        for(int i=0;i<n;i++)
        {
            if(f[i].size()==1)
            {
                int k=f[i][0];
                if(f[k].size()==1&&f[k][0]==i)
                dian++;
            }
        }
        dian/=2;
        if(m-maxn.w-dian<k)
        {
            cout<<n<<endl;
        }
        else
        {
            cout<<maxn.w+k+dian<<endl;
        }

    }
   return 0;
}
