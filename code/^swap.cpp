#include<stdio.h>
void swap(int *a,int *b)
{
    *a=*a^*b;*b=*b^*a;*a=*a^*b;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("%d %d",a,b);
    return 0;
}
