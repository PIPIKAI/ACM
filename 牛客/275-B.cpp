#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    ll n ;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1||n==2)
        {
            cout<<"1"<<endl;
        }
        else
            cout<<0<<endl;
    }
    return 0;
}
