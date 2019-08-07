#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=2e3+8;
int s[maxn],d[maxn],dp[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        mem(dp,0);mem(s,0);mem(d,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",s+i);
        }
        for(int i=2;i<=n;i++){
            scanf("%d",d+i);
        }
        dp[1]=s[1];
        for(int i=2;i<=n;i++){
            dp[i] = min( dp[i-1]+s[i] , dp[i-2]+d[i]);
        }
        string am="am";
        int ans=dp[n];
        int s=ans%60;
        int mi=(ans/60)%60;
        int h=(ans/3600)+8;
        h%=24;
        if(h>12){
            h-=12;
            am="pm";
        }
        printf("%.2d:%.2d:%.2d ",h,mi,s);
        cout<<am<<endl;
    }
    return 0;
}
