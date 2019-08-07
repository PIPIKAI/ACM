#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1002;
ll n,m;
ll f[maxn]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    while(m--){
        int x,y;
        ll ans=0;
        cin>>x>>y;
        for(int i=x;i<=y;i++){
            f[i]=log2(f[i]) +1;
        }
        for(int i=1;i<=n;i++){
            ans+=f[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
