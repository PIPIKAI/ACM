/*如图，如下的10个格子，填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）一共有多少种可能的填数方案？
请填写表示方案数目的整数。

*/
#include<stdio.h>

int map[10][10];
int book[10];
int sum=0;
int fabs(int i)
{
	return i>=0?i:(-i);
}
void dfs(int x,int y)
{
	int i;
	if(x==2&&y==3)
	{
		sum++;
		return ;
	}
	if(y==4)
	{
		x++;
		y=0;
	}

	
	if(x<0||x>2||y<0||y>3)
	return ;
	
	if((x==0&&y==0)||(x==2&&y==3))
		return ;
	
	for(i=0;i<10;i++)
	{
	
		if (x-1>=0&&fabs(map[x-1][y]-i)==1)
		continue;
		if (x-1>=0&&y-1>=0&&fabs(map[x-1][y-1]-i)==1)
		continue;
		if (x+1<3&&y+1<4&&fabs(map[x+1][y+1]-i)==1)
		continue;
		if (x+1<3&&fabs(map[x+1][y]-i)==1)
		continue;
		if (y+1<4&&fabs(map[x][y+1]-i)==1)
		continue;
		if (y-1>=0&&fabs(map[x][y-1]-i)==1)
		continue;
		if (x-1>=0&&y+1<4&&fabs(map[x-1][y+1]-i)==1)
		continue;
		if (y-1>=0&&x+1<3&&fabs(map[x+1][y-1]-i)==1)
		continue;
		if(0==book[i])
		{
			book[i]=1;
			map[x][y]=i;
		
			dfs(x,y+1);
			map[x][y]=-9;
			book[i]=0;
		}
		
	}
	
 } 
int main()
{
	for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)  
            map[i][j] = -9;  
	dfs(0,1);
	printf("%d",sum);
	return 0;
}
