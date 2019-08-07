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
int vis[102];
int n,m,maxn=0;
int f[102];
bool juge(){
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
        return false;
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        Max(maxn,f[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        mem(vis,0);
        int no=1,sum=0,now=i;
        for(;no<=maxn;){
            if(now>n)
            now=1;
            if(juge()){
                break;
            }
            if(vis[now]){
                now++;
                continue;
            }
            if(f[now]==no){
                sum+=f[now];
                vis[now]=1;
                no=1;
            }
            else{
                no++;
            }
            now++;
        }
        Max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}

