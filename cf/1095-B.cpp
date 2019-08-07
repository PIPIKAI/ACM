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
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    sort(f,f+n);
    if(n==2){
        cout<<0<<endl;
    }
    else{
        cout<<min( (f[n-2]-f[0]), f[n-1]-f[1]  )<<endl;
    }
    return 0;
}
