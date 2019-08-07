#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ca=1;
    while(cin>>t)
    {
        ca=1;
        while(ca<=t)
        {
            int n;
            cin>>n;
            int ta=1,a=1,b=1,sum=0,ans;
            for(int i=1;i<=n;i++)
            {
                int t;cin>>t;
                if(i==1)
                    ans=t;
                sum+=t;
                if(sum>ans)
                {
                    ans=sum,b=i;a=ta;
                }
                if(sum<0)
                {
                    sum=0;
                    ta=i+1;
                }
            }
            cout<<"Case "<<ca<<":"<<endl;
            cout<<ans<<" "<<a<<" "<<b<<endl;
            if(ca!=t)
                cout<<endl;
                ca++;
        }
    }

    return 0;
}
