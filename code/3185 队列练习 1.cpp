#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int flag=0;
typedef struct no
{
    int d;
    struct no *qnext,*anext;
}node;

typedef struct
{
    node *head,*tail;
}que;

que * inition()
{
    que *q;
    node *h,*t;
    h=(node*)malloc (sizeof (node));
    t=(node*)malloc (sizeof (node));
    q=(que*)malloc (sizeof(que));
    h->qnext=NULL;
    t->anext=NULL;
    t->qnext=h;
    h->anext=t;
    q->head=h;
    q->tail=t;
    return q;
}
void in(que *q)
{
    que *a=q;
    node *ne,*e;
    e=(node*)malloc (sizeof(node));
    ne=(node*)malloc (sizeof(node));
    e=a->tail->qnext;
    cin>>ne->d;
    ne->qnext=e;
    e->anext=ne;
    ne->anext=a->tail;
    a->tail->qnext=ne;
}
void out(que *q)
{
    node *tq,*t;
    tq=(node*)malloc (sizeof(node));
    t=(node*)malloc (sizeof(node));
    if(q->head->anext==q->tail)
    {
        flag=1;
        return ;
    }
    t=q->head->anext->anext;
    tq=q->head;
    tq->anext=t;
    t->qnext=tq;
}
void dis(que *q)
{
    node *t=q->head;
    if(flag)
    {
        cout<<"impossible!"<<endl;return;
    }
    else
        cout<<t->anext->d;
   /* if(q->head->anext==q->tail)
    {
        cout<<"impossible!"<<endl;return;
    }
    */

}
int main()
{
    int n;
    cin>>n;
    que *q=inition();
    while(n)
    {
        int a,b;
        cin>>a;
        if(a==1)
        in(q);
        else
        out(q);
        n--;
    }

    dis(q);

    return 0;
}
/*
5
2
2
1 1
2
1 9
*/
