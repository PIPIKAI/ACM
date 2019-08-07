#include<stdio.h>
typedef long long ll;
ll f;
int main()           
{
	ll n,f1=1,f2=1;

	scanf("%lld",&n);
	if(n==1||n==2)
	{
		printf("1\n");
		return 0;
	}
	n-=2;
	while(n>0)
	{
		if(n%2==1)
		f1=(f1+f2)%10007;
		else
		f2=(f1+f2)%10007;
		n--;
	}
	if(n%2==0)
	printf("%lld",f1%10007);
	else
	printf("%lld",f2%10007);
	return 0;
 } 
