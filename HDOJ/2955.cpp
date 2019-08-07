#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[1000005];
struct node
{
    int w;
    double v;
};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int T_T;
	cin>>T_T;
	while(T_T--)
    {
        node f[105];
        memset(dp,0,sizeof dp);
        double v;
        int n;
        cin>>v>>n;
        v=1-v;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>f[i].w>>f[i].v;
            sum+=f[i].w;
            f[i].v=1-f[i].v;
        }
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=sum;j>=f[i].w;j--)
            {
                dp[j]=max(dp[j],dp[j-f[i].w]*f[i].v);
            }
        }
        for(int i=sum;i>=0;i--)
        {
            if(dp[i]>=v)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
   return 0;
}
