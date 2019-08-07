#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
int n,m;
int f[maxn],t[maxn],d[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int p,x,y;
        cin>>p;
        if(p==1){
            cin>>x>>y;
            f[x]=y;
            t[x]=i;
        }
        else{
            cin>>x;
            d[i]=x;
        }
    }

    for(int i=m-1;i>=0;i--){
        d[i]=max(d[i],d[i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<max(f[i],d[t[i]])<<" ";
    }
    return 0;
}
