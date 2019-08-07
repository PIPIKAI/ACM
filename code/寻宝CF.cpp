#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string a,b,c;
ll f[300];
string ans[4]={"Kuro","Shiro","Katie","Draw"};
typedef struct {
    ll a;
    ll i;
}F;
bool cmp(F a,F c)
{
    return a.a<c.a;
}
void solve()
{
    cin>>a>>b>>c;
    F l[3];
    memset(f,0,sizeof(f));
    memset(l,0,sizeof(l));

    int flag=0;
    for(int i=0;i<3;i++)
        l[i].i=i;
    for(int i=0;i<a.size();i++)
    {
        f[a[i]]++;
        l[0].a=max(l[0].a,f[a[i]]);
    }
    memset(f,0,sizeof(f));
    for(int i=0;i<a.size();i++)
    {
        f[b[i]]++;
        l[1].a=max(l[1].a,f[b[i]]);
    }
    memset(f,0,sizeof(f));
    for(int i=0;i<a.size();i++)
    {
        f[c[i]]++;
        l[2].a=max(l[2].a,f[c[i]]);
    }

    for(int i=0;i<3;i++)
       {
           l[i].a+=-((l[i].a+n)%a.size());
       }
       sort(l,l+3,cmp);
    if(l[2].a==l[1].a&&l[0].a+n>a.size())
        cout<<ans[3]<<endl;
    else
        cout<<ans[l[2].i]<<endl;
}
int main()
{
    while(cin>>n)
    {
        solve();
    }
    return 0;
}
