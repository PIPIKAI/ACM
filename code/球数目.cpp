/*第一题 ：煤球数目
题目叙述： 
有一堆煤球，堆成三角棱锥形。具体： 
第一层放1个， 
第二层3个（排列成三角形）， 
第三层6个（排列成三角形）， 
第四层10个（排列成三角形）， 
…. 
如果一共有100层，共有多少个煤球？*/
#include<stdio.h>
int main()
{

	int sum=0,ceng=0;
	for(int i=1;i<=100;i++)
	{
		ceng+=i;
		sum=sum+ceng;
	}
	printf("%d",sum);
	return 0;
}
