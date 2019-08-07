#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
bool flag=0;
int ans[200006];
int k[32];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    bitset<31> f=n;
    f.to_string();
    int zero=f.count();
    if(m>=zero && m<=n){
        m-=zero;
        cout<<"YES"<<endl;
        for(int i=0;i<f.size();i++){
            if(f[i]==1){
                k[i]=1;
            }
        }
        for(int i=31;i>=0;i--){
            if(k[i]){
                while(m && k[i]){
                    k[i]--;
                    m--;
                    k[i-1]+=2;
                }
            }
        }
        for(int i=0;i<=31;i++){
            while(k[i]){
                int as=1<<i;
                cout<<as<<" ";
                k[i]--;
            }
        }
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
