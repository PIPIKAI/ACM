#include<stdio.h>
void swap(int  *a,int *b)
{
    int t;
    t=*a;*a=*b;*b=t;
    return ;
}
void qicksort(int f[],int begin,int end)
{
    int i,j;
    if(begin<end)
    {
        i=begin+1;
        j=end;
        while(i<j)
        {
            if(f[i]>f[begin])
            {
                swap(&f[i],&f[j]);
                j--;
            }
            else
            {
                i++;
            }
        }
        if(f[i]>=f[begin])
        {
            i--;
        }
        swap(&f[i],&f[begin]);
        qicksort(f,begin,i);
        qicksort(f,j,end);
    }
}
int main()
{
    int k,m,i,j,flag=0;
    scanf("%d%d",&k,&m);
    int f[m];
    for(i=0;i<m;i++)
        scanf("%d",&f[i]);
        qicksort(f,0,m-1);
    for(i=0,j=m-1;i<m&&i!=j;)
    {
        if(f[i]+f[j]>k)
        {
            j--;
        }
        else if(f[i]+f[j]<k)
        {
           i++;
        }
        else
        {
            printf("%d %d\n",f[i],f[j]);flag=1;
            i++;
        }
    }
    if(flag==0)
        printf("No Solution\n");

    return 0;
}
