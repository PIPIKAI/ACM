#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int ca=0;
    while(t--){
        ca++;
        cin>>n;
        cout<<"Case "<<ca<<":";
        for(int i=9;i>=0;i--){
                ll x= (10*n-i)/9;
                if((10*n-i)%9==0){
                    cout<<" "<<x;
                }
        }
        cout<<endl;
    }
    return 0;
}
