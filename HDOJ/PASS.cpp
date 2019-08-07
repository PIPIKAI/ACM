#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int t,n,m,k;
int f[10010],kk[10010];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
            mem(f,0);
            mem(kk,0);
        int sum=0;
        cin>>n>>m>>k;
        for(int i=1,t;i<=n;i++)
        {
            cin>>t;
            if(i<=n/2)
            f[t]++;
            kk[t]++;
        }
        for(int i=1;i<=1000;i++){
            sum+= min(f[i], kk[i]/k);
        }
        cout<<sum<<endl;
    }
    return 0;
}
