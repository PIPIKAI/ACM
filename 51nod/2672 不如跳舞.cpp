#include <bits/stdc++.h>
using namespace std;
const int maxn=1e2+7;
int n,m,dp[maxn][maxn];
string s[maxn];
int main(int argc, char * argv[]) {
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>s[i];
    for (int i = 0; i < n; ++i)
    	for(int j=0;j<n;j++)
			dp[i][j]= s[i][j]=='Y' ? 1 : maxn;
    for(int k=0;k<n;k++)
    	for (int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
	    		if(dp[i][j]>dp[i][k]+dp[k][j])
	    			dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
    cout<<(dp[0][1]>=maxn ? -1 : dp[0][1]-1)<<endl;
    return 0;
}