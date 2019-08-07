#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
const int maxn=2e5+7;
string s,ans;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(ans[ans.size()-1]!=s[i])
            ans+=s[i];
    }
    if(ans.size()%2)
        ans.erase(ans.size()-1);
    cout<<n-ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}
