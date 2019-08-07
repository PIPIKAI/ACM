#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll gcd(ll a,ll b){
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
    std::ios::sync_with_stdio(false);
    ll x,y,x1,x2,y1,y2,t,ca=0;
    cin>>t;
    while(t--){
        ca++;
        cin>>x1>>y1>>x2>>y2;
        cout<<"Case "<<ca<<": ";
         x=abs(x2-x1);
         y=abs(y2-y1);
         if(x==0&&y==0){
            cout<<1<<endl;
         }
         else if(x==0){
            cout<<y+1<<endl;
         }
         else if(y==0){
            cout<<x+1<<endl;
         }
         else{
            ll k= gcd(x,y);
            cout<<k+1<<endl;
         }
    }
    return 0;
}
