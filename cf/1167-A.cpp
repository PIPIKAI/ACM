#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int l=n;
        for(int i=0;i<n;i++){
            if(s[i]=='8'){
                l=i;
                break;
            }
        }
        if(n-l>=11){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
