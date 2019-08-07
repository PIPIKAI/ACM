#include<stdio.h>
void Hanoi(int n,char begin ,char mid,char end)
{
    if(n==1)
    {
         printf("%d from %c to %c\n",n,begin,end);

         return ;
    }
       Hanoi(n-1,begin,end ,mid);//n-1 dao begin to mid

       printf("%d from%c to %c\n",n,begin,end);
       // begin to end

       Hanoi(n-1,mid,begin ,end);
     // n-1   mid to end
     return ;
}
int main()
{
    int n;
    char A='A',B='B',C='C';
    scanf("%d",&n);
    Hanoi(n,A,B,C);
    return 0;
}
