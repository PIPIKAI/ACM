#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y)  (y>x)? x=y : x=x
int n,f[101][51][2]={0},ans;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    mem(f,-1);
    f[0][0][0]=f[0][0][1]=0;
    cin>>s>>n;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<2;k++){
                Max( f[i+1][j +( s[i]!= 'F') ][ k] ,f[i][j][k] + (k?1:-1));///把T变F
                Max( f[i+1][j +( s[i]!= 'T') ][!k] ,f[i][j][k] );///把F变T
            }
        }
    }
    for(int i=n;i>=0;i-=2){
        Max(ans,f[s.size()][i][0]);
        Max(ans,f[s.size()][i][1]);
    }
    cout<<ans<<endl;
    return 0;
}
