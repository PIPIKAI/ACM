#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  inf= 1e9+7;
#define mem(a,b)  memset( a,b,sizeof a)
ll n,l,r;
ll f[200050][3]={0},b[3]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>l>>r;
    while(l%3!=0)
    {
        b[l%3]++;
        l++;
    }
    while(r%3!=0)
    {
        b[r%3]++;
        r--;
    }
    b[0]++;
    for(int i=0;i<3;i++)
    {
         b[i]=(b[i]+(r-l)/3)%inf;
         f[1][i]=b[i];

    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                f[i][(j+k)%3]= (f[i][(j+k)%3]+f[i-1][j]*b[k])%inf;
            }
        }
    }
    cout<<f[n][0]<<endl;
    return 0;
}
