#include<bits/stdc++.h>
using namespace std;
int dp[1011],f[1010];
int main()
{
    int n;
    while(cin>>n,n!=0)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        cin>>f[i],dp[i]=f[i];
        for(int i=2;i<=n;i++)
        {
            int s=0;
            for(int j=1;j<i;j++)
            {
                if(f[j]<f[i]&&s<dp[j])
                    s=dp[j];
            }
            dp[i]+=s,ans=max(ans,dp[i]);
        }
            cout<<ans<<endl;
    }
    return 0;
}
