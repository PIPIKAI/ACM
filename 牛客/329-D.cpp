#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
ll n,m;
struct node
{
    ll time,p;
};
bool cmp(node a,node b)
{
    return a.p*b.time>b.p*a.time;
}
node f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    ll sum_time=0,sum_p=0,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>f[i].time>>f[i].p;
        sum_time+=f[i].time;
        sum_p+=f[i].p;
    }
    sort(f,f+n,cmp);
    for(int i=0;i<n;i++)
    {
        sum_time-=f[i].time;
        sum_p-=f[i].p;
        ans+=f[i].time*sum_p;
    }
    cout<<ans<<endl;
    return 0;
}
