#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
ll f[1000];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>f[i];
        }
        sort(f,f+n);
        ll ans=f[0]*f[n-1];
        bool flag=1;
        for(int i=1;i<n-1;i++){
            if(ans!=f[i]*f[n-1-i]){
                flag=0;
                break;
            }
        }
        ll cc=0;
        for(int i=2;i*i<=ans;i++){
            if(ans%i==0){
                cc+=2;
                if(i*i==ans)
                    cc--;
            }
        }
        if(flag&&cc==n){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
