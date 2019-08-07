#include<bits/stdc++.h>
using namespace std;
int f[102],dp[10005]={0};
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
   for(int i=0;i<n;i++)
    cin>>f[i];
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>0;j--)
        {
            if(j-f[i]>=0)
            dp[j]+=dp[j-f[i]];
        }
    }
    cout<<dp[m]<<endl;;
    return 0;
}

