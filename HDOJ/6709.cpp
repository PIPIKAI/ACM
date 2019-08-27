#include <bits/stdc++.h>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
ll n,k;
ll f[maxn];
vector<ll > c;
vector<ll> p;
bool cmp(ll a,ll b){
    return a>b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        p.clear();
        c.clear();
        ll sum1=0,sum2=0;
        cin>>n>>k;
        ll have=0;
        for(int i=0;i<n;i++){
            ll tp;
            cin>>tp;
            have+= (tp/k);
            ll a=tp/k;
            p.push_back((a+1)*k-tp);
            sum1+=tp;
            c.push_back(max((ll) 0, k-tp));
        }
        sort(c.begin(),c.end(),cmp);
        sort(p.begin(),p.end());
        ll need=n- have -1;
        ll ans=sum1+k;
        int i=0,j=0,cnt=0;
        while(cnt<need){
            if(p[i] < c[j]){
                ans+=p[i++];
            }
            else{
                ans+=c[j++];  
            }
            cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}