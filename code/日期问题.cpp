/*日期问题*/
#include<stdio.h>
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int min=1960,max=2059;
int f[3],book[3];
int is_run(int a)
{
	if(a%4==0||a%400==0)
	return 1;
	return 0;
}
int juge_month(int b)
{
	if(b>12||b<1)
	return 0;
	
	return 1;
	
}
int juge_day(int a,int b,int c)
{
	if(b!=2)
	{
		if(month[b-1]>=c)
	return 1;
	}
	else
	if(month[b-1]+is_run(a)>=c)
	return 1;
	
	return 0;
}
void ss(int a,int b,int c)
{
	if(a>=60)
	a+=1900;
	else
	a+=2000;
	if(1==juge_month(b)&&1==juge_day(a,b,c))
		{
			if(b<10&&c<10)
			printf("%d-0%d-0%d\n",a,b,c);
			else if(b<10&&c>=10)
			printf("%d-0%d-%d\n",a,b,c);
			else if(b>=10&&c<10)
			printf("%d-%d-0%d\n",a,b,c);
			else
			printf("%d-%d-%d\n",a,b,c);
			
		}
}
int main()
{
	int i,a,b,c;
	scanf("%2d/%2d/%2d",&a,&b,&c);
	
	ss(a,b,c);
	ss(c,a,b);
	ss(c,b,a);
	
	return 0;
}
