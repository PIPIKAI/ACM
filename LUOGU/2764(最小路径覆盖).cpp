#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
bitset<maxn> vis;
int head[maxn],cnt;
struct node
{
    int next,to;
}edge[maxn];
void add(int from,int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0,x,y;i<m;i++){
        cin>>x>>y;
        add(x,y+n);

    }
    for(int i=1;i<=n;i++){

    }
    return 0;
}
