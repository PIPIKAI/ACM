#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline ll read() {
    char c = getchar(); ll x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
ll n,m;
ll maxr;
struct node
{
    vector<ll >v[50006];
    vector<ll >s[50006];
};
node f;
void add(ll x,ll y,ll w)
{
    f.v[x].push_back(y);
    f.s[x].push_back(w);
}
inline void dfs(ll now,ll pre, ll s)
{
    if(s>maxr)
        maxr=s;
    for(int i=0;i<f.v[now].size();i++)
    {
        ll j=f.v[now][i];
        ll k=f.s[now][i];
        if(j!= pre)
        {
            dfs(j , now , s+k );
        }
    }
}
int main()
{
    n=read(),m=read();
    ll ans=0;
    for(int i=0;i<n-1;i++)
    {
        ll a,b,w;
        a=read(),b=read(),w=read();
        ans+=w;
        add(a,b,w);
        add(b,a,w);
    }
    ans*=2;
    maxr=0;
    dfs(m,0,0);
    cout<<ans-maxr<<endl;
    return 0;
}
