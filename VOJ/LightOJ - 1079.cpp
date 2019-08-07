#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,ans;
double p;
struct node{int p;double m;};
node f[1200];
double dp[12000];
int main()
{
    std::ios::sync_with_stdio(false);
    int t,ca(0);
    cin>>t;
    while(t--){
        ca++;
        int sum(0);
        cin>>p>>n;
        for(int i=0;i<n;i++){
            cin>>f[i].p>>f[i].m;
            sum+=f[i].p;
        }
        mem(dp,0);
        dp[0]=1;
        cout<<"Case "<<ca<<": ";
        for(int i=0;i<n;i++){
            for(int j=sum;j>=f[i].p;j--){
                if(dp[j-f[i].p]){
                    dp[j]=max(dp[j],dp[j-f[i].p] * (1-f[i].m) );
                }
            }
        }
        for(int i=sum;i>=0;i--){
            if(1-dp[i]<=p){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
