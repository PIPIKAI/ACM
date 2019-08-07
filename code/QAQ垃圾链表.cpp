#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct Node *pNext; /* 定义一个指针，
    指向下次个与当前结点数据类型相同的结点*/

}NODE,*PNODE;/*NODE等价于 struct Node; PNODE等价于struct Node *
 此处用大写是为了与变量区分，可以让人容易变出是个数据类型 */
PNODE Creat_list(void)
{
    int len;
    int i;
    int val;
    PNODE list;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));// 分配一个头文件
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
