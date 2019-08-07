#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    string ans="";
    int pt=1;
    for(int i=0;i<=s.size();i+=pt){
        ans+=s[i];
        pt++;
    }
    cout<<ans<<endl;
    return 0;
}
