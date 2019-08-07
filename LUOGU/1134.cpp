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
int n,m;
int ff=0,tt=0;
int ini(int k)
{
    while(k%2==0)
    {
        k/=2;
        tt++;
    }
    while(k%5==0)
    {
        k/=5;
        tt--;
        ff++;
    }
    return k;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans= (ans * ini(i) )%10;
    }
    for(int i=0;i<tt;i++)
    {
        ans= (ans*2)%10;
    }
    cout<<ans<<endl;
    return 0;
}
