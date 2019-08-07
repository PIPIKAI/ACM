#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int f[200050];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    sort(f,f+n);
    int ans=1;
    for(int i=0;i<n;i++){
        if(f[i]>=ans){
            ans++;
        }
    }
    cout<<ans-1<<endl;

    return 0;
}
