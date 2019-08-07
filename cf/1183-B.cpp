#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,k;
int f[200],maxx,minn;
int main()
{
    std::ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        maxx=-inf,minn=inf;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>f[i];
            maxx=max(maxx,f[i]);
            minn=min(minn,f[i]);
        }
        int p=maxx-minn;
        if(p > 2*k){
            cout<<-1<<endl;
            continue;
        }
        else{
            cout<<minn+k<<endl;
        }
    }
    return 0;
}
