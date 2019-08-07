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
ll n,k;
struct node
{
    ll x,y;
};

int vis[100050];
ll dis(node a,node b)
{
    return ( (a.x-b.x)*(a.x-b.x) +(a.y-b.y)*(a.y-b.y) );
}
int find(int x)
{
    while(vis[x]!=x)
    x=vis[x];
    return x;
}
void mer(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x<y)
    vis[y]=x;
    if(x>y)
    vis[x]=y;
}
int main()
{
    while(cin>>n>>k)
    {
        node f[100050];
        for(int i=1;i<=n;i++)
    {
        cin>>f[i].x>>f[i].y;
    }
    for(int i=0;i<=n;i++)
        vis[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(dis(f[i],f[j])<=k*k)
            {
                mer(i,j);
            }
        }
    }
    int a,b;
    cin>>a>>b;
    if(find(a)==find(b))
        cout<<"SUCCESS"<<endl;
    else
        cout<<"FAIL"<<endl;
    }
    return 0;
}
