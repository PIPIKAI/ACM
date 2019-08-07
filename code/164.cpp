#include<stdio.h>
#include<math.h>
void add(int i,int y)
{
    int sum=0,x=i,t,j,f;
    while(x>0)
    {

        t=x%10;
        for(j=1,f=t;j<y;j++)
        {
            t*=f;
        }
        x/=10;
        sum+=t;
    }

    if(sum==i)
    printf("Yes");
    else
        printf("No");
}
int main()
{
    int a,i,b=0;

    scanf("%d",&a);
    i=a;
    while(i>0)
    {
        i/=10;
        b++;
    }

    add(a,b);
return 0;
}



