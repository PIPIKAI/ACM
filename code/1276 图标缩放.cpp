/*
����:kaiss
��Ŀ:p1276 ͼ������
*/

#include <stdio.h>
int main()
{
    int i,j,a;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            printf("*");
        }
        for(j=0;j<a;j++)
        {
            printf("x");
        }
        for(j=0;j<a;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            printf(" ");
        }
        for(j=0;j<a;j++)
        {
            printf("xx");
        }

        printf("\n");
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            printf("*");
        }
        for(j=0;j<a;j++)
        {
            printf(" ");
        }
        for(j=0;j<a;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

