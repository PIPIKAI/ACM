#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,x,y;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>x>>y>>s;
    int ans=0;
    if(s[n-y-1]=='0'){
        ans++;
    }

    for(int i=n-x;i<n-y-1;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    for(int i=n-y;i<n;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
