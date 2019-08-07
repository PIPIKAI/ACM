#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
string a,b,tp;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>a>>b){
        int ans=0,sum=0;
        for(int i=0;i<b.size();i++){
                sum=sum^a[i]^b[i];
        }
        ans+= (sum%2 ? 0 : 1);
        for(int i=b.size();i<a.size();i++){
            sum=sum^a[i]^a[i-b.size()];
            ans+= (sum%2 ? 0 : 1);
        }
        cout<<ans<<endl;

    }
    return 0;
}
