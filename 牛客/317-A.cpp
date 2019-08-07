#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,x;
ll f[110][2];
void dd(ll work,ll with)
{
    if(work==1)
    {
        x=x-with;
    }
    else if(work==2)
    {
        x=with+x;
    }
    else if(work==3)
    {
        x=x/with;
    }
    else if(work==4)
    {
        x=with*x;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>x)
    {
        for(int i=0;i<n;i++)
            cin>>f[i][0]>>f[i][1];
        for(int i=n-1;i>=0;i--)
        {
            dd(f[i][0],f[i][1]);
        }
        cout<<x<<endl;
    }

    return 0;
}
