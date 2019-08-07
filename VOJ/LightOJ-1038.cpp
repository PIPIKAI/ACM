#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
const int maxn=1e5+7;
double dp[maxn];
void ini()
{
    for(int i=2;i<maxn;i++){
        double num=-1,ans=0;
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                num++;
                ans+=1+dp[i/j];
                if(i/j!=j){
                    num++;
                    ans+=1+dp[j];
                }
            }
            dp[i]=ans*1.0/num;
        }
    }
}
int main()
{
    int n,ca=0,t;
    cin>>t;
    ini();
    while(t--){
        ca++;
        cin>>n;
        cout<<"Case "<<ca<<": "<<fixed<<setprecision(6)<<dp[n]<<endl;
    }
    return  0;
}