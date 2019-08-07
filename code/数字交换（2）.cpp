#include<stdio.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;*a=*b;*b=t;
}
void findminmax(int *f,int n)
{
    int *min,*max;
    min=f,max=f;
    int *i,t;
    i=f;
   for(t=0;t<n;t++)
   {
       if(*(i+t)<*min)
       {
           min=i+t;
       }
       if(*(i+t)>*max)
       {
          max=i+t;
       }
   }
    swap(min,max);
}
int main()
{
    int n;scanf("%d",&n);
    int f[n],*i;
    for(i=f;i<f+n;i++)
        scanf("%d",i);
    findminmax(f,n);
    for(i=f;i<f+n;i++)
    {
    if(i==f+n-1)
        printf("%d\n",*i);
        else
            printf("%d ",*i);
    }
    return 0;
}
