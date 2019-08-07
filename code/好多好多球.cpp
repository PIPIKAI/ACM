#include<stdio.h>
#include<stdlib.h>
int n,a[102],dp[102];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	for(i=1;i<=n;i++)
	dp[a[i]]=dp[a[i]-1]+1;
	int max=0;
	for(i=1;i<=n;i++)
	{
		max=(dp[i]>max?dp[i]:max);
	}	
	printf("%d",n-max);
	return 0;
}
