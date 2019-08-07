#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
const int maxn=5e4+7;
int n,m,ans=0;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    int i,j;
    for( i=0;i<n;i++){
        int a=-1,b=maxn;
        for( j=i;j<n;j++){
            a=max(a,f[j]);
            b=min(b,f[j]);
            if(a-b==j-i){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
