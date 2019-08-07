#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct NODE{
    int n;
    struct NODE *next;
};
int n,s;
typedef struct NODE node;
typedef struct
{
    node *head,*tail;
}huan;
huan *  inti_link()
{
    huan * link;
    link =(huan * )malloc(sizeof(huan));
    node *h,*t;
    h=(node * )malloc(sizeof(node));
    t=(node * )malloc(sizeof(node));
    h->next=t;
    t->next=h;
    link->head=h;
    link->tail=t;
    return link;
}
void add_tail(huan * l,int date)
{
    node *tp,*tt=l->head;
    while(tt->next!=l->tail)
    {
       tt=tt->next;
    }
    tp=(node * )malloc(sizeof(node));
    tp->n=date;
    tt->next=tp;
    tp->next=l->tail;
    return ;
}
void dis(huan *l)
{
    node *h=l->head;
    while(h->next!=l->tail)
    {
        h=h->next;
        printf(" %d ",h->n);
    }
    printf("\n");
}
huan * creat_linkList()
{
    huan * link;
    link=inti_link();
    int i;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        add_tail(link,i);
    dis(link);
    return link;
}
void shanchu(huan *l,node *s)
{
    node *t=l->head;
    while(t->next!=s)
        t=t->next;
    t->next=t->next->next;
    return ;
}
void yue_se_fu(huan *l,int x)
{
    node * t=l->head;
    int cot=0;
    while(l->head->next->next!=l->tail)
    {

        cot++;
        t=t->next;
        if(cot==x)
        {
            cot=0;
            if(t!=l->head&&t!=l->tail)
            {
                shanchu(l,t);
                dis(l);
            }
        }
    }
    //printf("\n½á¹û=%d\n",l->head->next->n);
}
int main()
{
    huan * link;
    link=creat_linkList();
    yue_se_fu(link,s);
    return 0;
}
