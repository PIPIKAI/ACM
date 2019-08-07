#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    int a=1,b=0,ans=0;
    cin>>f[1];
    for(int i=2;i<=n;i++){
        cin>>f[i];
        if(f[i]==f[i-1]){
            a++;
        }
        else{
            ans=max(ans,2*min(a,b));
            b=a;
            a=1;
        }
    }
    ans=max(ans,2*min(a,b));
    cout<<ans<<endl;
    return 0;
}
