#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    ll n,p,flag=0;
    cin>>n;
    if(n&1)
    {
        for(ll i=3;i*i<=n;i++)
        {
            if(n%i==0)
            {
                flag=1;n-=i;break;
            }
        }
        if(!flag)
        cout<<1<<endl;
        else
        cout<<n/2+1<<endl;
    }
    else
    {
        cout<<n/2<<endl;
    }

    return 0;
}
