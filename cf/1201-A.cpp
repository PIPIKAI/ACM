#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e3+7;
int n,m;
string s[maxn];
map<char ,int> mp;
int f[maxn];
ll ans=0;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }for(int i=0;i<m;i++){
        cin>>f[i];
    }
        for(int j=0;j<m;j++){
            mp.clear();
            int mx=0;
            for(int i=0;i<n;i++){
                mp[s[i][j]]++;
                //cout<<s[i][j]<<endl;
                Max(mx,mp[s[i][j]]);
            }
            ans+=f[j]*mx;
        }
    cout<<ans<<endl;
    return 0;
}
