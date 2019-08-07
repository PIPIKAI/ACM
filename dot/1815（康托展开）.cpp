#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
string s;
ll tt(int n){
    ll res=n--;
    while(n>=1){
        res=n*res;
        n--;
    }
    return res;
}
ll dijida(string s){
    char t=s[0];
    ll r=0;
    for(int i=1;i<s.size();i++){
        if(s[i] < t){
            r++;
        }
    }
    return r;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>s;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        ans+= dijida(s.substr(i,i+s.size()-i))*tt(s.size()-i-1);
    }
    cout<<ans<<endl;
    return 0;
}
///X(s1) = a4*3! + a3*2! + a2*1! + a1*0!
