#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20];
ll dp[20][25];
/**
pos 代表当前位数
limit 代表当前能否能为9
lead 表示前导零
d 表示当前要算的数字
sum 表示答案
*/
ll l,r;
ll dfs(int pos,bool limit,bool lead , int d ,ll sum ){
	if(pos==-1) return sum;
	if(!limit&& !lead &&dp[pos][sum]!=-1) return dp[pos][sum];
	int up=limit ? f[pos]: 9;
	ll ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,limit && i==f[pos], lead&& i== 0 ,d, sum+( (i || !lead) &&(i==d) /*没有前导零*/)); 
	}
	if(!limit && !lead){
		dp[pos][sum]=ans;
	}
	return ans;
}
ll solve(ll x,int need){
	int pos=0;
	while(x){
		f[pos++]=x%10;
		x/=10;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(pos-1,1,1,need,0);
}
int main(int argc, char const *argv[]){
	cin>>l>>r;
	for(int i=0;i<10;i++){
		cout<<solve(r,i)-solve(l-1,i)<<endl;
	}
	return 0;
}