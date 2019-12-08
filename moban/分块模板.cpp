#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=5e5+7;
int n,m;
ll block,f[maxn], belong[maxn], num, l[maxn], r[maxn],sum[maxn];
void built(){
    block=sqrt(n);
    num=n/block;if(n%block) num++;
    for(int i=1;i<=num;i++){
        l[i]=(i-1)*block+1; ///每一块的左右边界
        r[i]=i*block;
    }
    r[num]=n;
    for(int i=1;i<=n;i++){
        belong[i]=(i-1)/block+1; /// 每个数属于哪一块
    }

    for(int i=1;i<=num;i++){
        for(int j=l[i];j<=r[i];j++){
            sum[i]+=f[j];///根据题意
        }
    }
}
void update(int x,int y){ ///第x个元素加上y
    f[x]+=y;
    sum[belong[x]]+=y;
}
ll query(int x,int y){
    ll ans=0;
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;i++){
            ans+=f[i];
        }
        return ans;
    }
    for(int i=x;i<=r[belong[x]];i++) ans+=f[i];
    for(int i=belong[x]+1;i<=belong[y]-1;i++) ans+=sum[i];
    for(int i=l[belong[y]];i<=y;i++) ans+=f[i];
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    built();
    while(m--){
        int x,y,c,k;
        cin>>c;
        if(c==2){
            cin>>x>>y;
            cout<<query(x,y)<<endl;
        }
        else{
            cin>>x>>y;
            update(x,y);
        }
    }
    return 0;
}
