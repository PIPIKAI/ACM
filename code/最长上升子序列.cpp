#include<stdio.h>
int n,f[1000],d[1000];
int LIS()
{
	int i,j,len=0;
	for(i=0;i<n;i++)
	{
		d[i]=1;
		for(j=0;j<i;j++)
		{
			if(f[j]<f[i]&&(d[j]+1)>d[i])
			d[i]=d[j]+1;
		}
		if(d[i]>len) len=d[i];
	}
	return len;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&f[i]);
	printf("%d",LIS());
	return 0;
}
