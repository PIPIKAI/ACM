/* 
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。*/
#include<stdio.h>
#define n 6
int map[9][9]={0};
int sum=0;
int dir[4][2]={1,0,0,1,0,-1,-1,0};
int fab(int a)
{
	return a>0?a:-a;
}
void dfs(int x1,int y1,int x2,int y2)
{
	if(x1>=7||x1<=1||y1>=7||y1<=1)
	{
		sum++;
		return ;
	}
	int cx1,cy1,cx2,cy2;
	for(int i=0;i<4;i++)
	{
		cx1=x1+dir[i][0];
		cy1=y1+dir[i][1];
		
		cx2=x2+dir[fab(3-i)][0];
		cy2=y2+dir[fab(3-i)][1];
		
		if(map[cx1][cy1]!=1)
		{
			map[cx1][cy1]=1;
			map[cx2][cy2]=1;
			dfs(cx1,cy1,cx2,cy2);
			map[cx1][cy1]=0;
			map[cx2][cy2]=0; 
		}
		
	}
	
}
int main()
{
	map[4][4]=1;
	dfs(4,4,4,4);
	printf("%d",sum/4);
	return 0;
 } 
