#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define true 1
#define false 0
typedef struct node//结点
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
        return ERROR ;/*第i个结点不存在*/
    *e =p->data;
    return OK;
}
int ClearList(linklist *l)
{
    linklist p,q;
    p=(*l)->next; //p指向第一个结点
    while(p)   //没到表尾
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*l)->next=NULL; // 头结点指针域为空
    return OK;
}
int main()
{

    return 0;
}
