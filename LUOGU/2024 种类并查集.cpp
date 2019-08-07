#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m,k;
int f[50005*3];
int find(int x)
{
    while(f[x]!=x){
        x=f[x];
    }
    return x;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<=n*3;i++){
        f[i]=i;
    }
    for(int i=0,ca,x,y;i<k;i++){
        cin>>ca>>x>>y;
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(ca==1){
            if(find(x+n)==find(y) || find(y+n)==find(x)){
                ans++;
            }
            else{
                 f[find(x)]=find(y);
                 f[find(x+n)]=find(y+n);
                 f[find(x+n+n)]=find(y+n+n);
            }
        }
        else{
            if(find(x)==find(y) || find(y+n)==find(x)){
                ans++;
            }
            else{
                f[find(x+n)]=find(y);
                f[find(x+n+n)]=find(y+n);
                f[find(x)]=find(y+n+n);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
