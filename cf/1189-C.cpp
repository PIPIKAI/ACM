#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e5+7;
int n,m;
int f[maxn];
int sum[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        sum[i]=f[i]+sum[i-1];
    }
    cin>>m;
    while(m--){
            int l,r;
        cin>>l>>r;
        cout<< (sum[r]-sum[l-1])/10<<endl;
    }
    return 0;
}
