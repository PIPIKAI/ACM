#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2e9+7
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
     if(((n+m+abs(m-n))%(k+1))==0)
    cout<<"HAI YOU SEI!"<<endl;
    else
        cout<<"LAOZI CHUI SI NI!"<<endl;
    return 0;
}
