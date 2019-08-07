#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][2];
int a[20],cnt=0;
ll dfs(int pos,int limit,int is6){
    if (pos==-1){
        if(is6) return 1;
        return 0;
    }
    if (!limit&&dp[pos][is6]!=-1)
        return dp[pos][is6];
    ll ans=0;
    int up=limit?a[pos]:9;
    for (int i=0;i<=up;i++){
        if (i==6){
            ans+=dfs(pos-1,limit&&(i==up),1);
        }
        else ans+=dfs(pos-1,limit&&(i==up),is6);
    }
    if (!limit){
        dp[pos][is6]=ans;
    }
    return ans;
}
ll solve(ll x){
    if (x==-1) return 0;
    cnt=0;
    memset(dp,-1,sizeof dp);
    while (x){
        a[cnt++]=x%10;
        x/=10;
    }
    return dfs(cnt-1,1,0);
}
int main(){
    ll l,r;
    scanf("%lld %lld",&l,&r);
    printf("%lld\n",solve(r)-solve(l-1));
    return 0;
}
