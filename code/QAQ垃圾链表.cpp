#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct Node *pNext; /* ����һ��ָ�룬
    ָ���´θ��뵱ǰ�������������ͬ�Ľ��*/

}NODE,*PNODE;/*NODE�ȼ��� struct Node; PNODE�ȼ���struct Node *
 �˴��ô�д��Ϊ����������֣������������ױ���Ǹ��������� */
PNODE Creat_list(void)
{
    int len;
    int i;
    int val;
    PNODE list;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));// ����һ��ͷ�ļ�
    if(NULL==pHead)
    {
        printf("Memory allocation failure");
        exit(-1);
    }
    else
    {
        PNODE pTail=pHead;
        pHead->pNext=NULL;
        printf("please input the length of list: ");
        scanf("%d",&len);
        for(i=0;i<len;i++)
        {
            PNODE p=(PNODE)malloc(sizeof(NODE));
            if(NULL==p)
            {
                printf("Memory allocation failure");
                exit(-1);
            }
            else
            {
                printf("please input the value of list: ");
                scanf("%d",&val);
                p->data=val;
                pTail->pNext=NULL;
                pTail=p;
            }
        }
    }
    return pHead;
}

int main()
{
    int n;
    Creat_list();
    scanf("%d",&n);
    int f[n][2];

    return 0;
}
