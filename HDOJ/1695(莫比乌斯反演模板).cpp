#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define MAX  100008
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
ll mu[1000002],prime[100005]={0};
bool vis[100005];
void ini()
{
    int N=MAX,cnt=0;
    mem(mu,0);
    mem(prime,0);
    mem(vis,0);
    mu[1]=1;
    cnt=0;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            mu[i]= -1;
        }
        for(int j=0;j<cnt&&i*prime[j]<N;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j])
                mu[i*prime[j]]= -mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
   //dis();
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,ca=1;
    ini();
    cin>>t;
    while(t--)
    {
        ll ans1=0,ans2=0;
        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;cout<<"Case "<<ca++<<": ";
        if(k==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        b/=k,d/=k;
        for(int i=1;i<=min(d,b);i++)
        {
            ans1+= mu[i]* (b/i) *(d/i);
        }
        for(int i=1;i<=min(b,d);i++)
            ans2+=mu[i]*(min(b,d)/i)*(min(b,d)/i);
        cout<<ans1-ans2/2;
            cout<<endl;
    }

    return 0;
}
