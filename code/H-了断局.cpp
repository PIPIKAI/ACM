#include<stdio.h>
typedef long long ll; 
ll gg[60]={0,1,1,2,4,7,13,24,44,81};
int main()
{
	int i;
	for(i=10;i<60;i++)
	{
		gg[i]=gg[i-1]+gg[i-2]+gg[i-3];
	}
    int n;
    while(~scanf("%d",&n))
    {
        printf("%lld\n",gg[n-1]);
    }
    return 0;
}
