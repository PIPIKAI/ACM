#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=1<<15;
struct node
{
    int data,cost;
    string s;
}f[maxn];
struct DP
{
    int pre,now,time,cost;
}dp[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>f[i].s>>f[i].data>>f[i].cost;
        }
        int toto=1<<n;///所有情况1000
        ///枚举所有情况i，如果一门课在i状态下完成了
        ///，比较i-j的扣分，和i的扣分
        for(int i=1;i<toto;i++){
            dp[i].cost=inf;
            for(int j=n-1;j>=0;j--){
                int k=1<<j;
                if(k&i){
                    //上一个状态
                    int last=i-k;
                    int pass=dp[last].time+f[j].cost-f[j].data;
                    pass=max(pass,0);
                    if(pass+dp[last].cost < dp[i].cost){
                        dp[i].cost=pass+dp[last].cost;
                        dp[i].now=j;
                        dp[i].pre=last;
                        dp[i].time=dp[last].time+f[j].cost;
                    }
                }
            }
        }
        cout<<dp[toto-1].cost<<endl;
        stack <int> s;
        int tmp=toto-1;
        while(tmp)
        {
            s.push(dp[tmp].now);
            tmp=dp[tmp].pre;
        }
        while(!s.empty())
        {
           cout<<f[s.top()].s<<endl;;
            s.pop();
        }
    }
    return 0;
}
