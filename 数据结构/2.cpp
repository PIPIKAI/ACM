/*
2. 显示出如下数组中的所有元素，并使用二分查找法在数组中查找元素。
int a[]={-90,-32,12,16,24,36,45,59,98,120};
输入输出示例
-90   -32   12   16   24   36   45   59   98   120
请输入所要查找的元素：24
输出：第5个元素为24，比较次数为1
请输入所要查找的元素：120
输出：第10个元素，比较次数为4
请输入所要查找的元素：6
输出：查找失败 比较次数为3
*/
#include<stdio.h>
int lower_(int *a,int l,int r,int s)
{
	int cishu=0,mid;
	while(l<=r)
	{
	  mid=(l+r)/2;
		cishu++;
		if(s<a[mid])
		{
			r=mid-1;
		}
		else if(s>a[mid])
		{
			l=mid+1;
		}
		else if(s==a[mid])
		{
			break;
		}
	}
	if(a[mid]==s)
	printf("第%d个元素，比较次数为%d\n",mid+1,cishu);
	else
	printf("查找失败，比较次数为%d\n",cishu);
}
int main()
{
	int a[]={-90,-32,12,16,24,36,45,59,98,120};
	for(int i=0;i<10;i++)
	{
		printf("%5d",*(a+i));
	}
	printf("\n");
	while(1)
	{
		int t;
		printf("请输入所要查找的元素： ");
		scanf("%d",&t);
		lower_(a,0,9,t);
	}

	return 0;
 }
