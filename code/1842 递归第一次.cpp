/*
����:kaiss
��Ŀ:p1842 �ݹ��һ��
*/
#include<stdio.h>
int vers(int n,int m,int g)
{

    m+=n+1;
    g++;
    if(g<0)
        return vers(m,n,g);
        else
        return m;
}
int main()
{
    int n,k=5,y=5;
    scanf("%d",&n);
    if(n>=0)
    {
        printf("5");
        return 0;
    }
    printf("%d",vers(k,y,n));
    return 0;
}
