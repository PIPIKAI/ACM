#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
ll yy[30];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int t,i=0;i<n;i++){
        cin>>t;
        int cnt=0;
        while(t){
            int p=t%2;
            yy[cnt++]+=p;
            t/=2;
        }
    }
    ll ans=0;
    for(int i=0;i<30;i++){
        ans+=(yy[i])*(n-yy[i]);

    }
     cout<<ans<<endl;
    return 0;
}
