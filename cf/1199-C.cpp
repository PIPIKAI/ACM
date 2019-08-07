#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=4e5+7;
ll n,m;
ll f[maxn],k[maxn],cnt;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    sort(f,f+n);
    ll tp=1;
    for(int i=1;i<=n;i++){
        if(f[i-1]!=f[i]){
            k[++cnt]=tp;
            tp=1;
        }
        else{
            tp++;
        }
    }
    ll need=(8 * m)/n,oop;
    if(need >=30){
        oop=cnt;
    }
    else{
        oop=1<<need;
    }
    //cout<<"oop="<<oop<<endl;
    ll ans=0,sum=0,count=0;
    for(int i=1;i<=cnt+1;i++){
        if(count >=oop){
            count=oop-1;
            sum=sum-k[i-oop];
        }
        sum+=k[i];
        count++;
        ans=max(ans,sum);
        //cout<<sum<<endl;
    }
    ans=max(ans,sum);
    cout<<n-ans<<endl;
    return 0;
}
/**
6 1
1 2 3  5  4 4
*/
