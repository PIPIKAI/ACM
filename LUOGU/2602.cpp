#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int f[20];
ll dp[20][20];
/**
pos 表示当前位数
limit 表示当前是否能为9
lead 表示前导0
d是当前要算的数字
sum表示的是操作答案，需要不断随dfs更新
*/
ll dfs(int pos,bool limit,bool lead,int d,ll sum)
{
    if(pos==-1) return sum;
    if(!limit &&!lead&&dp[pos][sum]!=-1) return dp[pos][sum];
    int up=limit ? f[pos] : 9;
    ll ans=0;
    for(int i=0;i<=up;i++){
        ans+=dfs(pos-1,limit && i==f[pos],lead && i==0, d,sum+( (i||!lead) &&(i==d) )) ;/*当没有前导0，或者当前位等于d时sum++*/
    }
    if(!limit && !lead)
    dp[pos][sum]=ans;
    return ans;
}
ll solve(ll x,int need)
{
    int pos=0;;
    while(x){
        f[pos++]=x%10;
        x/=10;
    }
    mem(dp,-1);
    return dfs(pos-1,1,1,need,0);
}
int main()
{
    ll n,m;
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<10;i++){
        cout<<solve(m,i)-solve(n-1,i);
        if(i!=9){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}
