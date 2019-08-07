#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans;
    bool flag=0;
    while(cin>>n)
    {
        ans=0;
        flag=0;
        int pre=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        if(i!=n)
        cin>>t;
        if(flag)
            continue;
        if(t-pre!=1)
            ans=i,flag=1;
        pre=t;
    }
        cout<<ans<<endl;
    }

    return 0;
}
