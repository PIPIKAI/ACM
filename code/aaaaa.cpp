#include<iostream>
using namespace std;
int m=20180415;
int aa(int a,int x)
{
    int s=1,t=a%m;
    while(x>0)
    {
    if(x%2==1)
    s=t*s%m;

    t=t*t%m;
    x/=2;
    }
    return s;
}
int main()
{
    int i,ans=1;
    int n;
    //cin>>n;
    for(i=2;i<=40000000;i++)
    {
        ans+=aa(i,5)%m;
    }
    cout<<ans<<endl;
    return 0;
}
