#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf =1000005;
#define mem(a,b)  memset( a,b,sizeof a)
ll f[1000006] , k[1000006] , p;
///  2^m*3^n% P = 1
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>p)
    {
        f[0]=1,k[0]=1;
        for(ll i=1;i<inf;i++)
        {
            f[i]=f[i-1]*2%p;
            k[i]=k[i-1]*3%p;
        }
        int flag=0;
        for(ll i=2;i<=p;i++)
        {
            for(ll j=1;j<i;j++)
            {
                if((f[j]*k[i-j]%p==1))
                {
                    cout<<j<<" "<<i-j<<endl;
                    flag=1;
                }
            }
            if(flag)  break;
        }

    }
    return 0;
}
