#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
ll n,a,b;
ll inf=1e10;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>a>>b>>n;
    ll k= a%b;
    for(int i=1;i<=n-10;i++)
    {
        k= ((k%b)*( inf %b))%b;
    }
   for(ll i=0;i<n+2;i++)
   {
       k*=10;
       if(i>=n-1)
       cout<<k/b;
       k%=b;
   }
    return 0;
}
