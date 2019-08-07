#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int k;
    while(cin>>k)
    {
        while(k--)
        {
            int n,i=0;
            cin>>n;
            while(1)
            {
                if(n-i<=0)
                {
                    break;
                }
                n-=i;
                i++;
            }
            if(n%9==0) cout<<"9"<<endl;
            else
                cout<<n%9<<endl;
        }

    }
    return 0;
}
