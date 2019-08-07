#include<stdio.h>
#include<math.h>

int sum=0,n,flag=1;
int temp[7];

int  together(int t[],int n)
{
    int i,s=0;
    if(t[0]==0)
        return 4;
    for(i=0;i<n;i++)
    {
        s=s*10+t[i];
    }
  //  printf("s=%d\n",s);
        return s;
}
int isapa(int n)
{
    int i;
    for(i=2;i<=sqrt(n)+1;i++)
        if(n%i==0)
        return 0;
    return 1;
}
void allpp(int book[],int a[],int step,int n,int temp[])
{
    int i,sss;
    if(step>=n)
    {
        sss=together(temp,n);
        if(!isapa(sss))
                flag=0;
    }
    for(i=0;i<n;i++)
       if(book[i]==0)
       {
           temp[step]=a[i];
           book[i]=1;
           allpp(book,a,step+1,n,temp);
           book[i]=0;
        }
    return ;
}

void chai (int n)
{
    int t=n,i=0;
    int a[7];
    while(t!=0)
    {
         a[i++]=t%10;
         t/=10;
    }
    int book[7]={0};
    int temp[7];
       allpp(book,a,0,i,temp);

}
int main()
{
    int n,m=1,i;
    scanf("%d",&n);
    while(n!=0)
    {
        m*=10;
        n--;
    }
    for(i=m/10;i<m;i++)
    {
        if(isapa(i))
            chai (i);
            else
                continue;
            if(flag)
               sum++;
                else
                    flag=1;
        //    printf("\n");
    }
        printf("%d\n",sum);

    return 0;
}
