#include<iostream>
#include<algorithm>
using namespace std;
int dp[30];
int k[30];
int g[30];
int main()
{
    int i,n=-1;
    int f[30];
    while(cin>>f[++n]);
    for(i=0;i<n;i++)
        g[i]=f[n-1-i];
    int len=0;int ans=0;
    dp[len]=f[0];
    k[ans]=g[0];
    for(i=1;i<n;i++)
    {
        if(k[ans]<g[i])
            k[++ans]=g[i];
            else
        {
            int j=lower_bound(k,k+ans,g[i])-k;
            k[j]=g[i];
        }

        if(dp[len]<f[i])
            dp[++len]=f[i];
        else
        {
            int j=lower_bound(dp,dp+len,f[i])-dp;
            dp[j]=f[i];
        }
    }
    cout<<ans+1<<endl<<len+1<<endl;
    return 0;
}
