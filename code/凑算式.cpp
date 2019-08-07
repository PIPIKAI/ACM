/*   B　　DEF 
A + __ + _____ = 10 
　　C　　 GHI
（如果显示有问题，可以参见【图1.jpg】） 
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

比如： 
6+8/3+952/714 就是一种解法， 
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？*/
#include<stdio.h>
float f[9];
int book[10]={0};
int sum=0;
float ss()
{
	return f[0]+f[1]/f[2]+(f[3]*100+f[4]*10+f[5])/(f[6]*100+f[7]*10+f[8]);
}
void dfs(int step)
{
	if(step==9)
	{
		if(10==ss())
		sum++;
	 } 
	 
	 for(int i=1;i<=9;i++)
	 {
	 	if(book[i]==0)
	 	{
	 		f[step]=i;
	 		book[i]=1;
	 		dfs(step+1);
	 		book[i]=0;
		 }
	 }
	
} 
int main()
{
	dfs(0);
	printf("%d",sum);
	return 0;
}
