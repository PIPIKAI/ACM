#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,k;
int f[500]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    int maxn=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        f[t]++;
        maxn=max(maxn,f[t]);
    }
    int ans=0;
    int z=0;
    while(maxn>0)
    {
        z++;
        maxn-=k;
    }
    for(int i=1;i<=100;i++)
    {
        if(f[i]!=0)
        ans+= abs(k*z-f[i]);
    }
    cout<<ans<<endl;
    return 0;
}
