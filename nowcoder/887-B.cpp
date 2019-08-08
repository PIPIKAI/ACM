#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
ll f[30];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<=n;i++){
            cin>>f[i];
        }
        if(n>=3){
            cout<<"No"<<endl;
        }
        else if(n==2){
            ll dd= f[1]*f[1]-4*f[0]*f[2];
            if(dd>=0){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}
