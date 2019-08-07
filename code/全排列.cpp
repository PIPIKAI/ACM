#include <stdio.h>
int x[30],n;
void swap(*a,*b)
{
	int *t;*t=*a;*a=*b;*b=*t;
}
void FullPermutation(int x[],int begin,int end)
{
	
	if(begin>=end)
	{
		int i;
		for(i=1;i<=end;i++)
		printf("%d ",x[i]);
		printf("\n");
	}
	else
	{
		
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		x[i]=i;
	}
   FullPermutation(x, 0, n);  

return 0;
}


