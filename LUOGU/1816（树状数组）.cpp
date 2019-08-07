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
const int maxn=1e5+7;
int n,m;
int f[maxn],a[maxn];
int lowbit(int x){
return x&(-x);
}
void update(int x,int val){
    while(x>0){
        f[x]=min(val,f[x]);
        x-=lowbit(x);
    }
}
int getmin(int l,int r){
    int ans=inf;
    while(l<=r){
        if(f[l])
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        f[i]=inf;
    for(int t,i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<getmin(l,r)<<" ";
    }
    return 0;
}
