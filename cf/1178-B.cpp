#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e6+7;
int n,m;
string s;
ll v[maxn],o[maxn],cnt,ans;

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++){
        v[i]=v[i-1];
        if(s[i]=='v'){
            if(s[i-1]=='v')
            v[i]++;
        }
        else{
            o[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;i++){
        int j=o[i];
        ans+= v[j-1]*( v[n-1]-v[j] );
    }
    cout<<ans<<endl;
    return 0;
}
