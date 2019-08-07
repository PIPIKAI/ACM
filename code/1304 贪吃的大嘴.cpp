#include<stdio.h>
void swap(int *p,int *q)
{
    int t;
    t=*p;*p=*q;*q=t;
}
void qicksort(int f[][0],int begin,int end)
{
    int i,j;
    if(begin<end)
    {
        i=begin+1;
        j=end;
        while(i<j)
        {
            if(f[i][0]>f[begin][0])
            {
                swap(&f[i][0],&f[j][0]);
                j--;
            }
            else
            {
                i++;
            }
        }
        if(f[begin][0]<=f[i][0])
            i--;
        swap(&f[i][0],&f[begin][0]);
        qicksort(f,begin,i);
        qicksort(f,j,end);
    }

}
int main()
{
    int max,m,bag=0,i,*p;
    scanf("%d%d",&max,&m);
    int f[m][2];
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&f[i][0],&f[i][1]);

    }
    qicksort(f,0,m-1);

    return 0;
}
