#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
int f[100];
int dp[11000];
int main()
{
    int n,sum=0,ans=0,b;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i],sum+=f[i];
    b=sum/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=b;j>=f[i];j--)
       {
           dp[j]=max(dp[j],dp[abs(j-f[i])]+f[i]);
           ans=max(dp[j],ans);
       }
    }
    ans=abs(ans*2-sum);
    cout<<ans<<endl;
    return 0;
}
