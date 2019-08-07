#include<stdio.h>
int a[10],book[10]={0},n=9;
int ans()
{
	return (a[1]*100+a[2]*10+a[3])+(a[4]*100+a[5]*10+a[6])-(a[7]*100+a[8]*10+a[9]);
}
void dfs(int step)  
{
	int i;
	if(step==n+1)
	{	
		if(ans()==0) 
		{
			for( i=1;i<=9;i++)
			{
				printf("%d",a[i]);
				if(i==3)
				printf(" + ");
				else if(i==6)
				printf(" = ");
			}
			printf("\n");
		}	
		return ;
	}
	for(i=1;i<=n;i++)
		if(book[i]==0)
	{
		a[step]=i;
		book[i]=1;
		dfs(step+1);
		book[i]=0; // »ØËÝ 
	}
	return ;
}

int main()
{
	dfs(1);	
	return 0;
}
