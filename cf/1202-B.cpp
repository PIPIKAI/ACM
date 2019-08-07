#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e5+7;
int n,m;
ll f[maxn],sum,mx;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
        sum+=f[i];
        Max(mx,f[i]);
    }
    if(sum&1){
        cout<<"NO"<<endl;
    }
    else{
        if(sum < mx*2 )
        cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
