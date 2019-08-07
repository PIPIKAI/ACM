#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(cin>>n)
    {
        int flag=1;
        for(int i=2;i<=n/2;i++)
    {
        if(i%2==0&&((n-i)%2)==0)
        {
            cout<<"YES"<<endl;
            flag=0;
            break;
        }
    }
    if(flag)
    cout<<"NO"<<endl;
    }

    return 0;
}
