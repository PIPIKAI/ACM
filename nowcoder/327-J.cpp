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
struct node
{
    ll spend,begin;
};
ll n,m;
node f[100050];

bool cmp(node a,node b)
{
    return a.begin<b.begin;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>f[i].spend;
    for(int i=0;i<n;i++)
    cin>>f[i].begin;
    sort(f,f+n,cmp);
    ll share=0,exam=2;
    for(int i=0;i<n;i++)
    {
        share= (share+f[i].begin-f[i-1].begin)-f[i].spend;
       /// cout<<share<<endl;
        if(share<0)
            return cout<<"NO"<<endl,0;
        share-=exam;
    }
    cout<<"YES"<<endl;
    return 0;
}
/**
3
2 2 2
2 6 10
*/
