#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=30;

int n,m;
ll ans=0;
ll f[maxn][maxn];
ll ta[maxn],tna;
ll tb[maxn],tnb;//保存a队和b队的人的index
void dfs(int now,ll sum)
{
    if(tna==n && tnb == n){
        ans=max(ans,sum);
        return ;
    }
    if(tna<n){
        ta[tna++]=now;
        ll mm=0;
        for(int j=0;j<tnb;j++){
            mm+=f[now][tb[j]];
        }
        dfs(now+1,sum+mm);
        tna--;
    }
    if(tnb<n){
        tb[tnb++]=now;
        ll mm=0;
        for(int j=0;j<tna;j++){
            mm+=f[now][ta[j]];
        }
        dfs(now+1,sum+mm);
        tnb--;
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n*2;i++){
        for(int j=0;j<n*2;j++){
            cin>>f[i][j];
        }
    }
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
