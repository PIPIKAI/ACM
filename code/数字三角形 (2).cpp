#include<stdio.h>
int f[105][105];
int max(int a,int b)
{
	return a>b?a:b; 
} 
int main()          
{
	int n,m;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=i;j++)
	scanf("%d",&f[i][j]);
	for(i=n;i>1;i--)
	{
		for(j=1;j<i;j++)
		{
			f[i-1][j]=max(f[i][j]+f[i-1][j],f[i][j+1]+f[i-1][j]);
			
		}
	}
	
	printf("%d\n",f[1][1]);
	return 0;
 } 
