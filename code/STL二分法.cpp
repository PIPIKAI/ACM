#include<stdio.h>
#include<algorithm>
int a[50001],dp[50001],n;
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	dp[1]=a[1];
	int len=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]>dp[len])
		{
			dp[++len]=a[i];
		}
		else
		{
			int j=std::lower_bound(dp+1,dp+1+len,a[i])-dp;
			if(dp[j]<a[i])
			dp[j]=a[i];
		}
		for(int i=1;i<=len;i++)
		printf("%d  ",dp[i]);
		printf("\n");
	}
	printf("%d",len);
}
