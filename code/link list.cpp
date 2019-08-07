#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int date;
	struct Node *pnext;//定义一个结构体指针，指向下一次与当前结点类型相同的类型的结点
}NODE,*PNODE;
NODE Creat_LinkList()
{
	int len;
	int i;
	int val;
	PNODE list;
	PNODE pHead=(PNODE)malloc(sizeof (NODE));
	if(NULL==pHead)
	{
		printf("Make Memory Failur!");
		exit(-1);
	}
	else
		{
			PNODE pTail=pHead;
			pHead->pnext=NULL;
			printf("lenth :");
			scanf("%d",&len);
			for(i=0;i<len;i++){
				PNODE p=(PNODE)malloc(sizeof(NODE));
				if(NULL==p)
				{
					printf("Make Memory Failur!");
					exit(-1);
				}
				else
				{
					scanf("%d",&val);
					p->date=val;
					pTail->pnext=p;
					p->pnext=NULL;
					pTail=p;
				 }

			}

			return pHead;
		}
}


int main()
{
	Creat_LinkList();

	return 0;
}
