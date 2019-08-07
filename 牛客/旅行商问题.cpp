#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
#define read(x) x=read()
const int maxn=5e4+4;
struct node{
    int w,to,next;
}edge[maxn*2];
int head[maxn],tot=1,ans=0,n;
void add(int a,int b,int w){
    edge[tot].to=b;
    edge[tot].w=w;
    edge[tot].next=head[a];
    head[a]=tot++;
}
void dfs(int now,int pre,int len){
    ans=max(len,ans);
    for(int i=head[now]; i ; i=edge[i].next){
        int tp=edge[i].to;
        if(pre==tp){
            continue;
        }
        dfs(tp,now,len+edge[i].w);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    read(n);
    int sum=0;
    for(int i=0,a,b,c;i<n-1;i++){
        read(a),read(b),read(c);
        sum+=c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0,0);
    ///cout<<ans<<endl;
    cout<<sum*2-ans<<endl;
    return 0;
}
