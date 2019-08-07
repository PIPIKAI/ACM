/*
作者:kaiss
题目:p3020 猪八戒吃桃
*/

#include <stdio.h>
typedef  unsigned long long ll;
int main()
{
    ll t,m;
    scanf("%llu%llu",&t,&m);
    ll f[m],i;
    for(i=0;i<m;i++)
    scanf("%llu",&f[i]);
    for(i=0;i<m;i++)
    {
    	t-=f[i];
    	if(t<=0)
    	{
    		printf("-%llu",i+1);
    		return 0;
		}
    	t*=2;
	}
	printf("%llu",t);
    return 0;
}

