#include<stdio.h>
long long  f[42];
 long long sum=0;
 long long  dp[42][42];
 long long  a[42][42];
 int k,n;
long long max(long long x,long long y)
{
	return x>y?x:y;
}
int main()
{
	int i,j,temp=0; 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
    {
        scanf("%1d",&f[i]);
    }
   for(i=1;i<=n;i++)
   {
   	for(j=i;j<=n;j++)
   	{
   		
   		a[i][j]=a[i][j-1]*10+f[j];
	}
   	
   }
   for(i=1;i<=n;i++)
   {
   	for(j=1;j<=n;j++)
   	printf("%4lld",a[i][j]);
   	printf("\n");
   }
  printf("%lld\n",sum);
    	return 0;
}

