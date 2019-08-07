#include<stdio.h>
int sub(int n);
int factorial(int n,int sum)
{

   sum*=n;
    n--;
    if(n==0)
        return sum;
        else
            return factorial(n,sum);

}
int sub(int n)
{
    int i,sum=0,k=1;
    for(i=1;i<=n;i++)
    {
        sum+=factorial(i,k);
    }
    return sum;
}
int main()
{
    int i,n,t,count=0;
    scanf("%d",&n);
   i=sub(n);
   printf("%d",i);
    return 0;
}

