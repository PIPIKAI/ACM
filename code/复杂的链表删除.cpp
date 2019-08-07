#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
typedef struct n
{
    int a;
    struct n *next;
}node;
node * inti()
{
    node * head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    return head;
}

void Tailadd(node * head)
{
    node *tail,*ne;
    ne=(node*)malloc(sizeof(node));
    tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    cin>>ne->a;
    tail->next=ne;
    ne->next=NULL;
}
void disp(node * head)
{
    node *h;
    h=(node*)malloc(sizeof(node));
    h=head;
    while(h->next!=NULL)
    {
        h=h->next;
        cout<<h->a<<" ";
    }
}

void delmemst(node * head,int a,int b)
{
    int c=1;
    node * h=head,*be,*en;
    be=(node*)malloc(sizeof(node));
    en=(node*)malloc(sizeof(node));
    while(h->next!=NULL)
    {
        if(c==a)
        {
            be=h;
        }
        if(c==b)
        {
            en=h->next;
            break;
        }
        h=h->next;
        c++;
    }
    be->next=en->next;
}
int main()
{
    node * head;
    head=inti();
    int n,i;
    while(cin>>n)
    {
        for( i=0;i<n;i++)
        Tailadd(head);
    cin>>n;
    for( i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        delmemst(head,a,b);
    }
    disp(head);
    }

    return 0;
}
