#include<iostream>
#include<cmath>
using namespace std;
int powa(int x,int n)
{
    int s=1;
    while(n>0)
    {
        s=s*x;
        n--;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    if(n<=153)
    {
        cout<<153;
        return 0;
    }
     else
     {
         for(int i=n;i<=1000000;i++)
         {
             int t=i,sum=0,g=0;
             while(t>0)
             {
                 t/=10;
                 g++;
             }
                t=i;
             while(t>0)
             {
                 int a=t%10;
                 sum+=powa(a,g);
                 t/=10;
             }
             if(sum==i)
             {
                 cout<<sum;
                 return 0;
             }
         }
     }
    return 0;
}
