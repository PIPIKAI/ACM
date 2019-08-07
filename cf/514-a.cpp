#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
ll n,m,a;
/// Ì°ÐÄ
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m>>a)
    {
      ll to=0,ans=0;
    for(int i=0;i<n;i++)
    {
        ll t,l;
        cin>>t>>l;
       // cout<<t-to<<endl;
        ans += (t-to)/a;
        to = l+t;
    }
    ans+= (m - to)/a;
    cout<<ans<<endl;
    }

    return 0;
}
