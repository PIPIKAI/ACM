#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define true 1
#define false 0
typedef struct node//���
typedef struct node *linklist
{
    int data ;
    struct node *next;
}node;

void CreatLinkListHead(linklist *L,int n)
{
    linklist p;
    int i;
    srand (time(0));
    *L=(linklist)malloc(sizeof(node));
    (*L)->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(linklist)malloc(sizeof(node));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;

    }
}

int GetElem (linklist l,int i,int *e)
{
    int j;
    linklist p;
    p=l->next;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }

    if(!p||j>i)
        return ERROR ;/*��i����㲻����*/
    *e =p->data;
    return OK;
}
int ClearList(linklist *l)
{
    linklist p,q;
    p=(*l)->next; //pָ���һ�����
    while(p)   //û����β
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*l)->next=NULL; // ͷ���ָ����Ϊ��
    return OK;
}
int main()
{

    return 0;
}
