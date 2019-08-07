#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    n=n*2;
    ll sum=(1+n)*n/2+1;
    cout<<sum<<endl;
    return 0;
}
