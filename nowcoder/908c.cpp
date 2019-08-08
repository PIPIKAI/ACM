#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m,t;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>t){
        while(t--){
             int x,ans=0;
            cin>>x;
            bitset<32> er(x);
            cout<<er.count()<<endl;
        }

    }

    return 0;
}
