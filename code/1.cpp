#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 50
//define date type
struct node{
	char No[10];
	char Name[20];
	struct node *pn;
};
typedef struct node NODE;

//set a list = NULL
NODE *InitialHeadNode()
{
	NODE *h;
	h = (NODE *)malloc(sizeof(NODE));
	h->pn = NULL;
	return h;
}
void InsertNode(NODE *h)
{
	NODE *NewNode,*pr;
	NewNode = (NODE *)malloc(sizeof(NODE)); //allocate address
	//initial date
	scanf("%s%s",NewNode->No,NewNode->Name); //date area
	NewNode->pn = NULL; //point area
	//rear insert
 	pr = h;   //search rear node = pr;
 	while(pr->pn != NULL)
 	{
 		pr =pr->pn;
	 }
	//insert
	pr->pn = NewNode;
	
	return;
}

void displayList(NODE *h)
{
	NODE *pt;
	pt = h;
	while(pt->pn != h)
	{
		pt = pt->pn;
		printf("  %-10s%-10s\n",pt->No,pt->Name);
	}
	return;
}

void CircleList(NODE *h)
{
	NODE *pr;
	pr = h;   //search rear node = pr;
 	while(pr->pn != NULL)
 	{
 		pr =pr->pn;
	 }
	 pr->pn = h; //link
	 return;
}

void Jessoph(NODE *h,int num)
{
	NODE *pt;
	int count=0;
	if(h->pn == h)
	{
		printf("list = NULL;\n");
		return;
	}
	
	pt = h;
	while(1)
	{
	    pt = pt->pn;
		count++;
		if(pt->pn == h)
		{
			pt = h;
		}
		
	
		if( h->pn->pn == h)
		{
			printf("The last one: %s  %s\n",h->pn->No,h->pn->Name);
			break;
		}
		
		if(count == num-1)
		{
			pt->pn = pt->pn->pn;
			count  = 0;
		}
			
	}
}

int main()
{
	freopen("1.txt","r",stdin);
	int i;
	NODE *head;
	head = InitialHeadNode();
	for(i=1;i<=10;i++)
	{
		InsertNode(head);
	}
	CircleList(head);
	displayList(head);
	
	Jessoph(head,2);
	return 0;
}
