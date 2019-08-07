#include<stdio.h>
int main()
{
    int l,n,f[10005]={0};
    int sum=0,a,b;
    int i;
    scanf("%d%d",&l,&n);
    for(i=0;i<n;i++ )
        {
            scanf("%d%d",&a,&b);
            for(int j=a;j<=b;j++)
                f[j]++;
        }

    for(i=0;i<=l;i++)
    {

        if(f[i]==0)
        {
            sum++;
        }
    }

    printf("%d",sum);

        return 0;
}


