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
int prim[100050]={0},mu[100050]={0},sum[100050]={0};
bool vis[100000]={0};
void ini(int N)
{
    int cnt=0;
    mu[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!vis[i]){mu[i]=-1;prim[++cnt]=i;}
        for(int j=1;j<=cnt&&i*prim[j]<=N;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=1;i<=N;i++)sum[i]=sum[i-1]+mu[i];
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    ini(60005);
    cin>>T;
    while(T--)
    {
        ll a,b,d;
        ll ans=0;
        cin>>a>>b>>d;
        for(ll i=1,j;i<=min(a,b);i=j+1)
        {
            j=min(a/(a/i),b/(b/i));
            ans+=(a/(i*d)) * (b/(i*d)) * (sum[j]-sum[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
