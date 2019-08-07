#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
    int a;
    struct node *pnext,*anext;
}node;

typedef struct
{
    node *h,*t;
}que;
void ma()
{
    cout<<"input a numbert:"<<endl<<"1 :headadd"<<endl<<"2 :tailadd"<<endl<<"3 :Shun_Xu_Dispaly_QUE"<<endl<<"4 :Ni_Xu_Dispaly_QUE"<<endl<<"5 :exit"<<endl;
}
que * inti()
{
    node *tail,*head;
    que *q;
    q=(que*)malloc(sizeof(que));
    tail=(node*)malloc(sizeof(node));
    head=(node*)malloc(sizeof(node));
    tail->pnext=NULL;
    head->anext=tail;
    head->pnext=NULL;
    tail->pnext=head;
    q->t=tail;
    q->h=head;
    return q;
}
void Tail_add(que *q)
{
    node *ne;
    node *tail_front;
    que *tq=q;
    ne=(node*)malloc(sizeof(node));
    cin>>ne->a;
    tail_front=q->t->pnext;

    tail_front->anext=ne;
    ne->pnext=tail_front;

    ne->anext=tq->t;
    tq->t->pnext=ne;
}
void Head_add(que *q)
{
    node *ne;
    node *head_after;
    que *tq=q;
    ne=(node*)malloc(sizeof(node));
    cin>>ne->a;
    head_after=q->h->anext;

    head_after->pnext=ne;
    ne->anext=head_after;

    ne->pnext=tq->h;
    tq->h->anext=ne;
}
void Shun_Xu_Dispaly_QUE(que *q)
{
    node *h=q->h;
    while(h->anext!=q->t)
    {
        h=h->anext;
        cout<<h->a<<" ";
    }
}
void Ni_Xu_Dispaly_QUE(que *q)
{
    node *t=q->t;
    while(t->pnext!=q->h)
    {
       t=t->pnext;
        cout<<t->a<<" ";
    }
}
int main()
{
    que *q;
    q=inti();
    while(1)
    {
        ma();
        int t;
        cin>>t;
        system("cls");
       if(t==1)
       {
           cout<<"input:"<<endl;
            Head_add(q);
       }

       else if(t==3)
       {
           Shun_Xu_Dispaly_QUE(q);
           system("pause");
       }
        else if(t==5)
            break;
        else if(t==2)
            {
               cout<<"input:"<<endl;
               Tail_add(q);
            }
        else if(t==4)
        {
            Ni_Xu_Dispaly_QUE(q);
            system("pause");
        }
        system("cls");
    }

    return 0;
}
