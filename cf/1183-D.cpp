#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
int n,m;
map<int,int> mp;
int a[maxn],cnt;
int main()
{
    std::ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
            int ans=0;
            cnt=0;
        mp.clear();
        cin>>n;
        for(int i=0,t;i<n;i++){
            cin>>t;
            mp[t]++;
        }
        for(int i=0;i<mp.size();i++){
            if(mp[i])
            a[cnt++]=mp[i];
        }
        sort(a,a+cnt);
        ans=a[cnt-1];
        for(int i=cnt-2;i>=0;i--){
            a[i]= max( 0,min( a[i+1]-1, a[i] ) );
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
