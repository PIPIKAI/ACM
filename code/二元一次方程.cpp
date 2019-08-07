#include<stdio.h>
typedef long long ll;
ll  a,b,c,d,e,f;// a*x+b*y=c
int x()
{
	return (c*e-f*b)/(a*e-d*b);
}
int main()           // d*x+e*y=f
{
	
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
	printf("%lld %lld",x(),(c-x()*a)/b);
	return 0;
 } 
