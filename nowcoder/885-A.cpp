#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
bool flag;
ll get_sum(ll x)
{
    ll s=0;
    while(x){
        s+=x%10;
        x/=10;
    }
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    ll t[2]={1,1};
    for(ll j=1;j<=100;j++){
        for(ll i=1;i<=100000000000;i++){
            ll tp=j*i;
            if(get_sum(tp)%j==0){
                cout<<tp<<endl;
                break;
            }
        }
    }


    return 0;
}
/**
15
195
16
448
17
476
18
198
19
874



*/
