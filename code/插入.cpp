#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct  mmmmm
{
    int num;
    struct mmmmm *next;
};
struct mmmmm*creatlinklist(int n)
{
    struct mmmmm *head,*pf,*pb;
    int i;
    for(i=0;i<n;i++)
    {
        pb=(struct mmmmm *) malloc(sizeof (struct mmmmm));
        printf("INPUT\n");
        scanf("%d",&pb->num);
        pb->next=NULL;
        if(i==0)
            pf=head=pb;
        else
        {
            pf->next=pb;pf=pb;
        }
    }
    return head;
};
