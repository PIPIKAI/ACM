#include<iostream>
using namespace std;
int strve(int a)
{
    int b=0;
    for(;a>0;a/=10)
    {
        b=b*10+a%10;
    }
    return b;
}
int main()
{
    int d;
    cin>>d;
    int ans=0;
    int n=1,t=d;
    while(t>0)
    {
         n*=10;
         t--;
    }

    for(int i=11;i<n;i++)
    {
        if(i%10==0)
            continue;
        if(strve(i)%i==0&&(strve(i)/i)!=1)
        {
           // cout<<i<<endl;
            ans++;
        }

    }
    cout<<ans<<endl;


    return 0;
}
