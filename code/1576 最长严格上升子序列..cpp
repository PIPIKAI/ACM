#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,len=0,f[5005],n;
    cin>>n;
    int dp[5005];
    for(i=0;i<n;i++)
        cin>>f[i];
    dp[0]=f[0];
    for(i=1;i<n;i++)
        if(dp[len]<=f[i])
            dp[++len]=f[i];
        else
        {
            int j=lower_bound(dp,dp+len,f[i])-dp;
            if(j==len)
            dp[j]=f[i];
        }
        for(i=0;i<=len;i++)
            cout<<dp[i]<<" ";
    //cout<<len+1;
    return 0;
}
