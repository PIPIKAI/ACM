#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e5+7;
int n,m,x,y;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=max(1,i-x);j<i;j++){
            if(f[i]>f[j]){
                flag=0;
                break;
            }
        }
        for(int j=min(n,i+y);j>i;j--){
            if(f[i]>f[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
