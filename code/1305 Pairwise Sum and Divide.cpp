#include<iostream>
using namespace std;
int f1=0,f2=0;
int ak(int a)
{
    int sum=0;
    for(int i=a-1;i>0;i--)
        sum+=i;
    return sum;
}
int main()
{
    int n,temp,i,sum=0;
    cin>>n;
    for( i=1;i<=n;i++)
    {
        cin>>temp;
        if(temp==1)
            f1++;
        if(temp==2)
            f2++;
    }

    cout<<2*ak(f1)+ak(f2)+n*f1-f1*f1;
    return 0;
}
