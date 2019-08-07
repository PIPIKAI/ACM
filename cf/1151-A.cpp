#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n;
string tar="ACTG";
int main()
{
    string s;
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    int ans=inf;
    for(int i=0;i<s.size();i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=min( abs(tar[j]-s[i+j]) ,abs(26-abs(tar[j]-s[i+j])) );
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
