#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
ll n,m,f[maxn],ans1,ans2,s[maxn];
ll start[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
     for(int i=0;i<n;i++){
         cin>>f[i];
         s[i]=s[i-1]+f[i];
     }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=(sum+f[i])%m;
        if(sum!= 0&& start[sum]==0){
            start[sum]=i;
        }
        else{
            ans1=max(ans1, s[i]-s[start[sum]] );
            ans2=max(ans2,i-start[sum]);
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
