#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll mod=1e9+7;
ll n,q;
ll f[100050]={0};
ll k[100050]={0};
ll tow[100050]={0};
void ini()
{
    tow[0]=1;
    for(int i=1;i<=100000;i++)
    {
        tow[i]=(tow[i-1]*2)%mod;
    }
    k[0]=0;
    for(int i=0;i<=100000;i++)
    {
        k[i]=(k[i-1]+tow[i-1])%mod;
        ///cout<<k[i]<<" ";
    }
    ///cout<<endl;
}
ll s(ll x,ll y)
{
    ll tt=y-x+2-(f[y]-f[x-1]+1);
    ///cout<<"tt== "<<tt<<endl;
    return (k[y-x+1]%mod-k[tt]%mod+mod)%mod;
}
void dis()
{
     {
         for(int i=1;i<=n;i++)
        cout<<f[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    ini();
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        f[i]+=f[i-1];
        if(c=='1')
        {
            f[i]++;
        }
    }

   ///dis();///
   while(q--)
   {
       int x,y;
       cin>>x>>y;
       cout<<s(x,y)%mod<<endl;
   }
    return 0;
}
/**
7 5
1001110

1 2
2 2
2 3
4 7
3 7

4 2
0101
1 3
2 4

*/
