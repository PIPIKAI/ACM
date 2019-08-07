#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int f[600][600];
int ans[600];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    int t=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>f[i][j];
        }
    }
    if(t==0){
        cout<<"NIE"<<endl;
    }
    else{
        cout<<"TAK"<<endl;
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
