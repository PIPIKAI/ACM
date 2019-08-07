#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000000];
int ww[150];
int vv[150];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n,v,ans=0,to=0;
    cin>>n>>v;
    int key[101]={0};
    for(int i=0;i<n;i++)
    {
        cin>>vv[i]>>ww[i];
        key[i+1]=key[i]+vv[i];
        to+=ww[i];
    }
    if(key[n]<=v)
        cout<<to<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=v;j>=max(vv[i],(v-(key[n]-key[i])));j--)
        {
            dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
            ans=max(ans,dp[j]);
        }
        }
        cout<<ans<<endl;
    }

   return 0;
}

