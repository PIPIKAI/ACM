#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int ri[500000];
int dow[500000];
int dp[500000];
int f[500002];

int main()
{
    int n,ans=0;
    while(cin>>n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",f+i);
            int k=lower_bound(dp,dp+cnt,f[i])-dp;
            dp[k]=f[i];
            if(k==cnt)
                cnt++;
            ri[i]=cnt;
            ans=max(ri[i],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

