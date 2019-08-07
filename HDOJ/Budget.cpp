#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e3+7;
int n,m;
string s[maxn];
int main()
{
    while(cin>>n){
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int now=0,updata=0;
        for(int i=0;i<=n;i++){
            int t=0,flag=0;
            for(int j=0;j<s[i].size();j++){
                if(flag){
                    t=t*10+(s[i][j]-'0');
                }
                if(s[i][j]=='.'){
                    flag=1;
                }
            }
            int tp=t%10;
            if(tp >=5){
                ans+= (10-tp);
            }
            else{
                ans-=tp;
            }
        }
        double pt= 0.001*ans;
        cout<<fixed<<setprecision(3)<<pt<<endl;
    }
    return 0;
}
