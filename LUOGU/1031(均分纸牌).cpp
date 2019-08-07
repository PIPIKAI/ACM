#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m,sum,f[200];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
        sum+=f[i];
    }
    sum/=n;
    int ans=0;

    for(int i=1;i<n;i++){
        if(f[i-1]!=sum){
            ans++;
        }
        f[i]=f[i]-(sum-f[i-1]);
        f[i-1]=sum;
    }
    cout<<ans<<endl;
    return 0;
}
