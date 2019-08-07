#include<stdio.h>
long long  f[1000000];
int main()
{

    int n;
    long long  sum=1,i=0;
    while(sum<=1000000000)
    {
        f[i]=sum;
        i++;
        sum+=i;

    }
    scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
        int temp;
        scanf("%d",&temp);
        for(int j=0;j<=44721;j++)
        {
            if(f[j]==temp)
            {
                printf("1\n");
                break;
            }
            if(f[j]>temp)
            {
                printf("0\n");
                break;
            }

        }
    }

    return 0;
}
