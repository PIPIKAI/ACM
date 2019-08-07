#include<stdio.h>
#include<math.h>
typedef long long ll ;
int isapa(ll n)
{
	int i;
	for(i=2;i<=sqrt(n)+1;i++)
	if(n%i==0)
	return 0;

	return 1;
}
int main()
{
	ll cha,i,n,j,temp,add;
	int len=10;
	for(i=2;i<1000000000;i++)
	{
		if(isapa(i))
		{
			for(j=1;j<10000;j++)
			{
				 add=i;
				for( temp=0;temp<10;temp++)
				{
					add+=j;
					if(0==isapa(add))
					break;
				}
				if(temp==9)
				{
				    printf("%d\n",i);
					printf("%d",j);
					return 0;
				}


			}
		}
	}
	return 0;
}
