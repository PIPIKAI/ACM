#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
const ll maxx=(ll) 0xffffffff+1;
ll n,x;
int f[20];
ll dp[10][2000];
ll ha[16]={6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
ll dfs(int pos,int limit,ll sum){
    if(pos<0){
        return sum;
    }
    if(!limit && dp[pos][sum]!=-1) return dp[pos][sum];
    int v=limit? f[pos] : 15;
    ll ans=0;
    for(int i=0;i<=v;i++){
        ans+=dfs(pos-1,limit&&(f[pos]==i), sum+ha[i]);
    }
    if(!limit)
    dp[pos][sum]=ans;
    return ans;
}
ll solve(ll now)
{
    int cnt=0;
    mem(f,0);
    while(now){
        int tp=now%16;
        f[cnt++]=tp;
        now/=16;
    }
    return dfs(7,1,0);
    
}
int main()
{
    int T;
    mem(dp,-1);
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lx",&n,&x);
        n--;
        ll r=x+n;
        if(r>=maxx){
            r=r%maxx;
            printf("%lld\n",solve((ll)maxx-1)-solve(x-1)+solve(r) );
        }
        else{
            printf("%lld\n",solve(r)-solve(x-1) );
        }
    }
    return 0;
}