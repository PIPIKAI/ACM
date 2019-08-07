#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=508;
struct node
{
    int w,v;
}f[maxn];
int dp[10008];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    int emp,full;
    cin>>T;
    while(T--){
        mem(dp,0);
        cin>>emp>>full;
        full=full-emp;
        cin>>n;
        dp[0]=inf;
        for(int i=0;i<n;i++){
            cin>>f[i].w>>f[i].v;
        }
        for(int i=0;i<n;i++){
            for(int j=f[i].v;j<=full;j++){
                dp[j]=dp[j]==0 ?dp[j-f[i].v] + f[i].w :min (dp[j-f[i].v]+f[i].w,dp[j] );
            }
        }
        if(dp[full]==inf){
            cout<<"This is impossible."<<endl;
        }
        else{
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[full]-inf<<"."<<endl;
        }
    }
    return 0;
}
