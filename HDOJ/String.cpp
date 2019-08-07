#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
string s;
int f[300];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        cin>>s;
        mem(f,0);
        for(int i=0;i<s.size();i++){
            int t= s[i]-'a';
            f[t]++;
        }
        ll k;
        ll a=f[0]*f['v'-'a']*f['i'-'a']*f['n'-'a'];
        ll b=1;
        for(int i=0;i<4;i++){
            b=b*n;
        }
        k=__gcd(a,b);
        a/=k;
        b/=k;
        cout<<a<<"/"<<b<<endl;


    }
    return 0;
}
