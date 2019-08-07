/*
作者:kaiss
题目:p1384 黑色星期五
*/
#include <stdio.h>
int isrun(int n)
{
    if(n%400==0||(n%4==0&&n%100!=0))
        return 1;
    else
        return 0;
}
int main()
{
    int n,i,j,k,t=0,count[7]={0},month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int year=1900;
    scanf("%d",&n);
    for(i=year;i<1900+n;i++)//year
    {
        if(isrun(i)==1)
            month[1]=29;
        else
            month[1]=28;
       for(k=0;k<12;k++)//month
       {
           for(j=0;j<month[k];j++, t++)
           {
                if(t>6)
                t=0;
               if(j==12)
                count[t]++;
           }
       }
    }
    printf("%d %d %d %d %d %d %d",count[5],count[6],count[0],count[1],count[2],count[3],count[4]);
    return 0;
}


