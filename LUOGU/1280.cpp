#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x,y;
}f[10005];
ll dp[10005]={0};
ll st[10005]={0};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>f[i].x>>f[i].y,st[f[i].x]++;
    for(int i=n;i>=1;i--)
    {
        if(st[i]==0)
            dp[i]=dp[i+1]+1;
        else
        {
            for(int j=k-1;j>=0;j--)
            {
                if(f[j].x==i)
                 dp[i]=max(dp[i+f[j].y],dp[i]);
            }
        }

    }
    cout<<dp[1]<<endl;
   return 0;
}
