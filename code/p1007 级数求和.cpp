/*
����:kaiss
��Ŀ:p1007 �������
*/

#include <stdio.h>
int main()
{
    int k,i=1,count=0;
    scanf("%d",&k);
    double sum=0;
    while(sum<=k)
    {

        sum+=1.0/i*1.0;
        i++;
        count++;
    }
    printf("%d",count);
    return 0;
}

