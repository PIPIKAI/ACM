#include<stdio.h>
typedef long long ll;

	
 
int main()
{int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	long long f[n+3][m+3];
	int i,j;
	
	f[0][0]=1;
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0&&j==0)
			{
				f[i][j]=1;
			}
			else if((i==x&&j==y)||(i==x-1&&j==y-2)||(i==x+1&&j==y-2)||(i==x-2&&j==y-1)||(i==x+2&&j==y-1)||(i==x-2&&j==y+1)||(i==x+2&&j==y+1)||(i==x-1&&j==y+2)||(i==x+1&&j==y+2))
            {

			
				f[i][j]=0;
			}
			
			else if(i==0&&j!=0)
			{
				f[i][j]=f[i][j-1];
			}
			else if(i!=0&&j==0 )
			{
				f[i][j]=f[i-1][j];
			}
			else 
			{
			   f[i][j]=f[i-1][j]+f[i][j-1];
			}
		
		}
	}
	
	
	printf("%ld\n",f[n][m]);
	return 0;
}
