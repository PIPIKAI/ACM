#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e8
#define MAX 50005
int dp[MAX];
int h=MAX/2;
int n,m;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int TnT;
	cin>>TnT;
	while(TnT--)
    {
        for(int i=0;i<MAX;i++)
            dp[i]=-inf;
        dp[h]=0;
        cin>>n;
        int ans=0,i,j;
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(a>=0)
            {
                for(int j=b+h;j>=0;j--)
                    dp[j+a]=max(dp[j+a],dp[j]+c);
            }
            else
            {
                for(int j=b+h;j<MAX;j++)
                    dp[j+a]=max(dp[j+a],dp[j]+c);
            }
        }
        for(int i=0;i<MAX;i++)
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
   return 0;
}
