#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct nod
{
	int date;
	struct nod *next;
};
typedef struct  nod  node;
node * inintion()
{
	node *p=new node;
	p->next=NULL;
	return p;
}
void headadd(node *h)
{
	node *p =new node;
	scanf("%d",&p->date);
	p->next=h->next;
	h->next=p;
}
void tailadd(node *h)
{
	node *p=new node;
	scanf("%d",&p->date);
	while(h->next!=NULL)
	{
		h=h->next;
	}
	p->next=h->next;
	h->next=p;
}
void dis(node *h)
{
	while(h->next!=NULL)
	{
		h=h->next;
		printf(" %d ->",h->date);
	}
	printf("\n");
}
int main()
{
	node *lis=new node;
	lis = inintion();
	for(int i=0;i<5;i++)
	tailadd(lis);
	dis(lis);
	return 0;
 } 
