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
int f[550][550]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();m=read();
    int ans=0,minn=-99999;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int t=read();minn=max(minn,t);
            f[i][j]=f[i][j-1]+t;
        }
    for(int i=0;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            for(int k=1,s=0;k<=n;k++)
            {
                s+=f[k][j]-f[k][i];
                if(s<0) s=0;
                ans=max(ans,s);
            }
    if(ans==0) ans=minn;
    cout<<ans<<endl;
    return 0;
}
