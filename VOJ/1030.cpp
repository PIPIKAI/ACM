#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
const int maxn=105;
int f[maxn];
double dp[maxn];
int main()
{
    int n,ca=0,t;
    double ans;
    cin>>t;
    while(t--){
        mem(f,0);
        mem(dp,0);
        ans=0;
        ca++;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>f[i];
        }
        dp[n-1]=f[n-1];
        for(int i=n-2;i>=0;i--){
            int step=min(6,n-i-1);
            dp[i]=f[i];
            for(int j=1;j<=step;j++){
                dp[i]+=1.0/step*dp[i+j]*1.000 ;
            }
        }
        cout<<"Case "<<ca<<": "<<fixed<<setprecision(6)<<dp[0]<<endl;
    }
    return  0;
}
///dp[k] = 1 / min(m,6) * (dp[k + 1] + dp[k+2] + … + dp[min(m,6)]) ＋ gold[k]