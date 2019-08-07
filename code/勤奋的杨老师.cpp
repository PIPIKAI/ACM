#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int ri[500000];
int dow[500000];
int dp[500000];
int f[500002];

int main()
{
    int n;
    while(cin>>n)
    {

        for(int i=0;i<n;i++)
            cin>>f[i];
        int len;
        for(int i=0;i<n;i++)
        {
            len=0;
            memset(dp,0,sizeof(dp));
            dp[len]=f[0];
            for(int j=0;j<=i;j++)
            {
                if(dp[len]<=f[j])
                    dp[++len]=f[j];
                else
                {
                    int k=upper_bound(dp,dp+len,f[j])-dp;
                    dp[k]=f[j];
                }
            }
            ri[i]=len;
        }

        for(int i=0;i<n;i++)
        {
            len=0;
            memset(dp,0,sizeof(dp));
            dp[len]=f[n-1];
            for(int j=n-1;j>=i;j--)
            {
                if(dp[len]<=f[j])
                    dp[++len]=f[j];
                else
                {
                    int k=upper_bound(dp,dp+len,f[j])-dp;
                    dp[k]=f[j];
                }
            }
            dow[i]=len;
        }
        int ans=1;
        for(int i=0;i<n-1;i++)
        {
            cout<<ri[i]<<" "<<dow[i]<<endl;
            ans=max(ans,dow[i+1]+ri[i]);
        }

        cout<<ans<<endl;
    }

    return 0;
}
