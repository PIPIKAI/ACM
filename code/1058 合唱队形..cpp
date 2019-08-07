#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,len=0,a[200]={0},b[200]={0},f[200]={0},dp[200];
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&f[i]);
        int j=lower_bound(dp,dp+len,f[i])-dp;
        dp[j]=f[i];
        if(j==len)
            len++;
        a[i]=len;
    }
    len=0;
    memset(dp,0,sizeof(dp));
    for(i=n-1;i>0;i--)
    {
        int j=lower_bound(dp,dp+len,f[i])-dp;
        if(len==j)
            len++;
        dp[j]=f[i];
        b[i]=len;
    }
    int ans=1;
    for(i=0;i<n;i++)
        ans=max(ans,a[i]+b[i+1]);
      //  cout<<a[i]<<" ";
    cout<<n-ans<<endl;
    return 0;
}
