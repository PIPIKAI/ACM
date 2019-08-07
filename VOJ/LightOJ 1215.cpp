#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll a,b,c,l;
int main()
{
    int t,ca=0;
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        ca++;
        cin>>a>>b>>l;
        cout<<"Case "<<ca<<": ";
        ll p=__gcd(a,b);
        ll q=  (a*b)/p;
        if((l%q)==0){
            c=l/q;
            ll d=__gcd(q,c);
            while(d!=1){
                c*= d;
                q/=d;
                d=__gcd(q,c);
            }
            cout<<c<<endl;
        }
        else{
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}
