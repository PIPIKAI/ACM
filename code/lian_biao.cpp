#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
typedef struct n
{
    int a;
    struct n *next;
}node;
void ma()
{
    cout<<"input a numbert:"<<endl<<"1 :headadd"<<endl<<"2 :tailadd"<<endl<<"3 :display"<<endl<<"4 :del a->b"<<endl<<"5 :insert element"<<endl<<"6 :Sortadd"<<endl<<"7 :delete_linklist"<<endl<< "8 :exit"<<endl;
}

node * inti()
{
    node * head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    return head;
}

void delete_linklist(node *head)
{
    head->next=NULL;
}
void insert_element(node *head,int a,int x)//插入元素
{
    node * ne,*t=head,*e;
    int i=1;
    ne=(node*)malloc(sizeof(node));
    while(i<a&&t->next!=NULL)
    {
        i++;
        t=t->next;
    }
    e=t->next;
    ne->a=x;
    t->next=ne;
    ne->next=e;
}
void Sortadd(node *head)// 顺序输入
{
    node * ne,*t=head;
    int i=1;
    ne=(node*)malloc(sizeof(node));
    cin>>ne->a;
    while(t->next!=NULL)
    {
        t=t->next;
        if(t->a>ne->a)
        {
            insert_element(head,i,ne->a);
            return ;
        }
        i++;
    }
    insert_element(head,i,ne->a);
}
void Headadd(node * head) //头插法
{
    node * ne,*t;
    ne=(node*)malloc(sizeof(node));
    t=head->next;
    cin>>ne->a;
    head->next=ne;
    ne->next=t;
}
void Tailadd(node * head) // 尾插法
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
void disp(node * head) // 输出
{
    cout<<endl<<endl;
    node *h;
    h=(node*)malloc(sizeof(node));
    h=head;
    if(h->next==NULL)
    {
        cout<<"link List is NULL"<<endl;
    }
    while(h->next!=NULL)
    {
        h=h->next;
        cout<<h->a<<"  ";
    }
    cout<<endl;
}
void del_element(node * head,int a,int b) // 删除 a 到 b的元素
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
    while(1)
    {
        ma();
        int t;
        cin>>t;
        system("cls");
       if(t==1)
       {
           disp(head);
           cout<<"input:"<<endl;
           Headadd(head);
       }

       else if(t==3)
       {
           disp(head);
           system("pause");
       }
        else if(t==7)
            delete_linklist(head);
        else if(t==8)
            break;
        else if(t==6)
        {
            int n;
            cout<<"how many element you need add?"<<endl;
            cin>>n;
            cout<<"please input "<<n<<" element"<<endl;
            while(n>0)
            {
                n--;
                Sortadd(head);
            }
        }
        else if(t==2)
            {
                disp(head);
               cout<<"input:"<<endl;
               Tailadd(head);
            }
        else if(t==4)
        {
            disp(head);
            int a,b;
            cout<<" a->b will be del"<<endl;
            cin>>a>>b;
            del_element(head,a,b);
        }
        else if(t==5)
        {
            disp(head);
            int a,x;
            cout<<"where element you want to insert"<<endl;
            cin>>a>>x;
            insert_element(head,a,x);
        }

        system("cls");
    }
    return 0;
}
