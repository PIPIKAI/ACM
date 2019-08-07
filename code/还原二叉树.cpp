#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef struct node{
    char data;
    node *ltree,*rtree;
}T;
T * creat_tree(char a[],char b[],int l)
{
    T *t;
    char *p;
    if(l==0)
        return NULL;
    t=(T *)malloc(sizeof(T));
    t->data=a[0];
    for(p=b;p;p++)
    {
        if(*p==a[0])
        break;
    }
    int ll=p-b;
    t->ltree=creat_tree(a+1,b,ll);
    t->rtree=creat_tree(a+1+ll,p+1,l-ll-1);
    return t;
}
void after_oder(T *t)
{
    if(t==NULL) return ;
    after_oder(t->ltree);
    after_oder(t->rtree);
    printf("%c",t->data);
}
int main()
{
    char a[500],b[500];
    T *t;
    scanf("%s%s",a,b);
    t=creat_tree(a,b,strlen(a));
    after_oder(t);
    //int depth=depth_t(t);
    return 0;
}
