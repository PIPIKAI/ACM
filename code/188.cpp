#include<stdio.h>
double pi = 3.1415926; 
int main() 
{
	int n,R,r;
	scanf("%d%d%d",&n,&R,&r);
	if(n==1&&R==r)
	{
		printf("Yes\n");
		return 0;
	}
	double ar=2*r*1.0/(R-r);
	if(2*pi/ar<n)
	printf("No\n");
	else
	printf("Yes\n");
	printf("%.3lf",ar);
	return 0;
}
