#include<iostream>
using namespace std;
int f[50];
int dp[20001];
int main()
{
    int n,v;
    int i,j,k;
    cin>>v>>n;
    for(i=0;i<n;i++)
        cin>>f[i];
    dp[0]=0;
    for(j=0;j<n;j++)
        for(i=v;i>=f[j];i--)
            dp[i]=max(dp[i-f[j]]+f[j],dp[i]);
    cout<<v-dp[v]<<endl;
    return 0;
}
