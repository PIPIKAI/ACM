/*牌型种数


小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？


请填写该整数，不要填写任何多余的内容或说明文字。*/

#include<stdio.h>
int n=13,book[14];
long long sum=0;
void dfs(int step)
{
	int i,j;
	if(step==n+1)
	{
		sum++;
		return ;
	}
	
	for(j=0;j<14;j++)
	{
		if(book[j]<4)
		{
			book[j]++;
			dfs(step+1);
			book[j]=0;
		}
	}
	return ;
}
int main()
{
	dfs(1);
	printf("%d",sum);
	return 0;
}
