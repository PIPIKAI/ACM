/*
2. ��ʾ�����������е�����Ԫ�أ���ʹ�ö��ֲ��ҷ��������в���Ԫ�ء�
int a[]={-90,-32,12,16,24,36,45,59,98,120};
�������ʾ��
-90   -32   12   16   24   36   45   59   98   120
��������Ҫ���ҵ�Ԫ�أ�24
�������5��Ԫ��Ϊ24���Ƚϴ���Ϊ1
��������Ҫ���ҵ�Ԫ�أ�120
�������10��Ԫ�أ��Ƚϴ���Ϊ4
��������Ҫ���ҵ�Ԫ�أ�6
���������ʧ�� �Ƚϴ���Ϊ3
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
	printf("��%d��Ԫ�أ��Ƚϴ���Ϊ%d\n",mid+1,cishu);
	else
	printf("����ʧ�ܣ��Ƚϴ���Ϊ%d\n",cishu);
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
		printf("��������Ҫ���ҵ�Ԫ�أ� ");
		scanf("%d",&t);
		lower_(a,0,9,t);
	}

	return 0;
 }
