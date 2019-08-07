#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll& x,ll& y){
    if(a%b==0){
        x=0,y=1;
        return b;
    }
    ll r,tx,ty;
    r=exgcd(b,a%b,tx,ty);
    x=ty;
    y=tx-a/b*ty;
}

ll comp(ll a,ll b,ll m){
    if(a<b) return 0;
    if(a==b) return 1;
    if(b>a-b) b=a-b;
    ll ans=1,ca=1,cb=1;
    for(int i=0;i<b;i++){
        ca=ca*(a-i)%m;
        cb=cb*(b-i)%m;
    }
    ll x,y;
    exgcd(cb,m,x,y);
    x=(x%m+m)%m;
    ans=ca*x%m;
    return ans;
}

ll lucas(ll a,ll b,ll m){
    ll ans=1;
    while(a&&b){
        ans=(ans*comp(a%m,b%m,m))%m;
        a/=m;
        b/=m;
    }
    return ans;
}

int main()
{
    ll a,b,m;
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b>>m;
        cout<<lucas(a+b,b,m)<<endl;
    }
    return 0;
}
