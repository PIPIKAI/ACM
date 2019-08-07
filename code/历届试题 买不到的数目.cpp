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
int vis[1000050];
int k[2];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>k[0]>>k[1];
    vis[k[0]]=vis[k[1]]=1;
    for(int i=0;i<=1e6;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(i>k[j]&&vis[i-k[j]])
                vis[i]=1;
        }
    }
    for(int i=1e6;i>=0;i--)
    {
        if(!vis[i])
            return cout<<i<<endl,0;
    }
    return 0;
}
