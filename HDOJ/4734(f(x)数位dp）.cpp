#pragma comment(linker, "/STACK:10240000,10240000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
const double R=0.5772156649015328606065120900;
const int N=1e5+5;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
ll fact[20];
void init()
{
    fact[0]=1;
    for(int i=1;i<20;i++)
        fact[i]=fact[i-1]*10%mod;
}
struct node
{
    ll cnt,sum,sqr;
    node(ll cnt=-1,ll sum=0,ll sqr=0):cnt(cnt),sum(sum),sqr(sqr){}
}dp[20][7][7];
int a[20];
ll fac(ll x)
{
    return x*x%mod;
}
ll dfs(int pos,ll num,ll val,ll&cnt,ll&sum,bool limit)
{
    if(pos==-1) {
        if(num==0 || val==0)
            return 0;
        cnt=1;
        return 0;
    }
    if(!limit && dp[pos][num][val].cnt!=-1) {
            cnt=dp[pos][num][val].cnt;
            sum=dp[pos][num][val].sum;
            return dp[pos][num][val].sqr;
    }
    int up=limit?a[pos]:9;
    ll sq=0;
    for(int i=0;i<=up;i++)
    if(i!=7)
    {
        ll cn=0,su=0;
        ll tmp=dfs(pos-1,(num+i)%7,(val*10+i)%7,cn,su,limit && i==a[pos]);
        ll tm=i*fact[pos]%mod;
        tmp=(tmp+fac(tm)*cn%mod+(tm*su%mod)*2%mod)%mod;//计数之后要更新sum,sqr
        sum=(sum+su+(i*fact[pos]%mod)*cn%mod)%mod;
        cnt=(cnt+cn)%mod;
        sq=(sq+tmp)%mod;
    }
    if(!limit) dp[pos][num][val]=node(cnt,sum,sq);
    return sq;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    ll t1=0,t2=0;
    return dfs(pos-1,0,0,t1,t2,true);
}
bool judge(ll x)
{
    int sum=0;
    int pos=0;
    if(x%7==0) return false;
    while(x)
    {
        if(x%10==7) return false;
        sum+=x%10;
        x/=10;
    }
    sum%=7;
    return sum!=0;
}
int main()
{
    init();
    for(int i=0;i<20;i++)
        for(int j=0;j<7;j++)
        for(int k=0;k<7;k++)//memset
    {
        dp[i][j][k].cnt=-1;
        dp[i][j][k].sum=0;
        dp[i][j][k].sqr=0;
    }
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        ll le,ri;
        scanf("%I64d%I64d",&le,&ri);
        ll ans=solve(ri)-solve(le-1);
        ans=(ans%mod+mod)%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
