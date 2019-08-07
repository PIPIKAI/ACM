#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2e9+7
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
vector<ll> f[100050];
bool cmp(ll a,ll b)
{
    return a>b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll t,r;
        cin>>t>>r;
        f[t].push_back(r);
    }
    for(int i=1;i<=100000;i++)
    {
        if(f[i].size()!=0)
        sort(f[i].begin(),f[i].end(),cmp);
    }
    for(int i=1;)
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}
