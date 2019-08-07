#include<bits/stdc++.h>
using namespace std;
#define MAX 1000+7
int dp[MAX][MAX]={0};
int t[MAX][MAX]={0};
int main()
{
    string s,es;
    cin>>s;
    es=s; reverse(es.begin(),es.end());
    int len=s.length(),ans=0;
    s='@'+s;es='@'+es;
    memset(dp,0,sizeof dp);
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=len;j++)
        {
            if(s[i]==es[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        ans=max(dp[i][len],ans);
    }
    cout<<len-ans<<endl;
    return 0;
}
