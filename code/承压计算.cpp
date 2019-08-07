#include<stdio.h>
#include<math.h>

double max(double a,double b)
{
	return a>b?a:b;
}
double min(double a,double b)
{
	return a<b?a:b;
}
double s(double a)
{
	return a/2;
}	
double f[32][32];
int main()
{
	int n =30,i,j;
	double  max=0,min=999999;

	for(i=0;i<29;i++)
	{
		for(j=0;j<=i;j++)
		scanf("%lf",&f[i][j]);
	 } 
	 for(i=1;i<=29;i++)
	 {
	 	f[i][0]+=s(f[i-1][0]);
	 		for(j=1;j<i;j++)
	 		{
	 			f[i][j]+=s(f[i-1][j-1]+f[i-1][j]);
	 			
			 }
			f[i][i]+=s(f[i-1][i-1]); 
	 }
	 for(i=0;i<=29;i++)
	 {
	 	if(max<f[29][i])
	 	max=f[29][i];
	 	if(min>f[29][i])
	 	min=f[29][i];
	 }
	 printf("%lf  %lf \n",max,min);
	 printf("%lf",2086458231/min*max);
	return 0;
}
