#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[50050];
int main()
{
    int i,n,len=1,temp;
    scanf("%d",&n);
    scanf("%d",&dp[1]);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&temp);
        if(temp>dp[len])
        {
            dp[++len]=temp;
        }
        else
        {
            int j=lower_bound(dp+1,dp+len+1,temp)-dp;
            dp[j]=temp;
        }
    }
    printf("%d",len);
    return 0;
}
