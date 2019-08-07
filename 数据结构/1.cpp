/*
1、请输入字符串，最多输入4个字符串，要求后输入的字符串排在前面，例如：
输入：EricZ
输出：1=EricZ
输入：David
输出：1=David 2=EricZ
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack_
{
	char s[250];
}stk[500];
void dis(int k)
{
	for(int i=k-1;i>=0;i--)
	printf("%d = %s  ",k-i,stk[i].s);
	printf("\n");
}
int main()
{
	char ss[250];
	int k=0;
	while(~scanf("%s",stk[k++].s))
	{
		dis(k);

	}
	return 0;
 } 
