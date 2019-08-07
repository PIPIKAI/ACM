#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e5+7;
int n,k;
int f[maxn],ans;
int dp[maxn][105][3];//dp[i][j]±íÊ¾
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(f[i]==j){
                dp[i][j][0]=i;
            }
            else{
                dp[i][j][]
            }
        }
    }
    return 0;
}
