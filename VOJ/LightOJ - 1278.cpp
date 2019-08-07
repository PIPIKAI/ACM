#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
const int maxn=1e7;
int prime[maxn/10],cnt=0;
bool vis[maxn];
void ini()
{
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int t,ca=0;
    cin>>t;
    ini();
    while(t--){
        ca++;
        cin>>n;
        cout<<"Case "<<ca<<": ";
        ll ans=1,t=sqrt(n);
        for(ll i=0;i<cnt&&prime[i]<=sqrt(n);i++){
            ll tp=0;
            while(n%prime[i]==0){
                tp++;
                n/=prime[i];
            }
            if(prime[i]%2)
            ans*=(tp+1);
        }
        if(n>1&&n%2){
            ans<<=1;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
