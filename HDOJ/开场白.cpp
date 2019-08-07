#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int t,m;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>t;
    string ts="2050";
    while(t--){
        bool flag=1;
        cin>>s;
        for(int i=0;i<s.size();){
            if(s.substr(i,4)==ts){
                i+=4;
            }
            else{
                flag=0;
                break;
                continue;
            }
        }
        flag ?cout<<"Yes"<<endl :  cout<<"No"<<endl;
    }
    return 0;
}
