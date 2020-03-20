#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+7;
int n,f[maxn],dp[maxn],len;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    dp[0]=f[0];
    for(int i=1;i<n;i++){
        if(dp[len]<=f[i]){
            dp[++len]=f[i];
        }
        else
        {
            int j=lower_bound(dp,dp+len,f[i])-dp;
            if(j==len)
            dp[j]=f[i];
        }
    }    
    cout<<len+1<<endl;
    return 0;
}
