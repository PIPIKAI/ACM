/*历届试题 波动数列  
时间限制：1.0s   内存限制：256.0MB
    
问题描述
　　观察这个数列：
　　1 3 0 2 -1 1 -2 ...

　　这个数列中后一项总是比前一项增加2或者减少3。

　　栋栋对这种数列很好奇，他想知道长度为 n 和为 s 而且后一项总是比前一项增加a或者减少b的整数数列可能有多少种呢？
输入格式
　　输入的第一行包含四个整数 n s a b，含义如前面说述。
输出格式
　　输出一行，包含一个整数，表示满足条件的方案数。由于这个数很大，请输出方案数除以100000007的余数。
样例输入
4 10 2 3
样例输出
2
样例说明
　　这两个数列分别是2 4 1 3和7 4 1 -2。
*/
#include<stdio.h>
#include<string.h>
#define MAX 1100
#define MOD 100000007
int   dp[2][MAX*MAX]={0};
int e=0;
long long n,s,a,b;
int ans=0;
int main()
{	
	scanf("%lld%lld%lld%lld",&n,&s,&a,&b);
	long long  i,j,t;
	dp[e][0]=1;
	for(i=1;i<=n;i++)
	{
	e=1-e;
		for(j=0;j<=i*(i+1)/2;j++)
		{
			if(i>j)
			dp[e][j]=dp[1-e][j];
			else
			dp[e][j]=(dp[1-e][j-1]+dp[1-e][j-i])%MOD;
			}	
	}
	for(i=1;i<=n*(n-1)/2;i++)
	{
		t=s-i*a+b*(n*(n-1)/2-i);
		if(t%n==0)
		{
			ans=(ans+dp[e][i])%MOD;
		}
	}
	printf("%lld",dp[n][s]);
	return 0;
 } 
