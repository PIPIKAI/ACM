#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);//n pep m try
	int i,j;
	int f[45][45]={0};
	f[0][1]=1;
	for(i=1;i<=m;i++)
	{
		f[i][1]=f[i-1][n]+f[i-1][2];
		f[i][n]=f[i-1][n-1]+f[i-1][1];
		for(j=2;j<n;j++)
		{
			f[i][j]=f[i-1][j+1]+f[i-1][j-1];
		}
	 } 
	 
	printf("%d",f[m][1]);	
	return 0;
 } 
