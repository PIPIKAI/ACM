#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
int  vi[10005],wi[10005];
int dp[10005]={0};
int main()
{
   int n,w,ans=0;
   cin>>n>>w;
   for(int i=1;i<=n;i++)
   {
       cin>>vi[i]>>wi[i];
   }

   for(int i=1;i<=n;i++)
       for(int j=w;j>=vi[i];j--)
       {
           dp[j]=max(dp[j],dp[j-vi[i]]+wi[i]);ans=max(dp[j],ans);
       }

   cout<<ans<<endl;
    return 0;
}


