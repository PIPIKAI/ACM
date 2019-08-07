#include<stdio.h>
int MMP[10]={6,2,5,5,4,5,6,3,7,6};
int n;//need to be zero
int aaaaaa(int MM)
{
    int sum=0;
    if(MM/10==0)
        return MMP[MM];
    else
    {
        while(1)
        {
            sum+=MMP[MM%10];
            if(MM/10==0)
            return sum;
            else
                MM/=10;
        }
        printf("%d",MM);
    }
}
int huo_chai_gun(int A,int B)
{

    if(aaaaaa(A)+aaaaaa(B)+aaaaaa(A+B)==n)
        return 1;
    return 0;
}
int main()
{
    scanf("%d",&n);
    n-=4;
    int sum=0;
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
    {
        if(huo_chai_gun(i,j))
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}
