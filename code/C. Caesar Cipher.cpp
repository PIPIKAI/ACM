#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int main()
{
    string a,b,c,ans;
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        cin>>n>>m;
        cin>>a>>b>>c;
        ans="";
        int key=b[0]-a[0];
        if(key<0){
            key+=26;
        }
        char tp;
        for(int i=0;i<m;i++){
             tp= 'A'+ (c[i]-'A' - key + 26 )%26;
            ans+=tp;
        }
        cout<<"Case #"<<cas<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
