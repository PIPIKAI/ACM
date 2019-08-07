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
int f[150];
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();
    int ans=0,res=-1000;
    for(int i=1;i<=n;i++)
        f[i]=read();
    f[0]=0;f[n+1]=1001;
    for(int i=1;i<=n;i++)
    {

        if(f[i]==f[i-1]+1&&f[i]==f[i+1]-1)
            ans++;
        else{
            ans=0;
        }res=max(ans,res);

    }
        cout<<res<<endl;
    return 0;
}
