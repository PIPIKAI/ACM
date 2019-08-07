#include<stdio.h>
int sum=0,f[10],n,deter[10][10];
int abs_(int a)
{
    return a>0?a:-a;
}
void Queen(int k)
{
    int i;
    if(k>=n)
    {
        for(i=0;i<n;i++)
        printf("%d ",f[i]);
        printf("\n");
            sum++;
        return ;
    }

    for(i=0;i<n;i++)
    {
      int j;
      if(deter[k][i]==0)
        continue;
            for(j=0;j<k;j++)
            {
                if(abs_(f[j]-i)==abs_(k-j)||i==f[j])
                    break;
            }
            if(j==k)
            {
               f[k]=i;
                Queen(k+1);
            }
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&deter[i][j]);
    Queen(0);
    printf("%d",sum);
    return 0;
}
/*
            1 1 0 1
            0 1 1 1
            1 1 1 0
            1 0 1 1
*/
