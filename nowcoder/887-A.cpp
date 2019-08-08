#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
string s;
vector<string> ans;
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        int z[2]={0,0},cnt=1;
        string tp="";
        for(int i=0;i<s.size();i++){
           if(s[i]=='0'){
            tp+=s[i];
            z++;
           }
           else{
            z=0;
           }

        }
        if(tp.size()){
            ans.push_back(tp);
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        ans.clear();
    }
    return 0;
}
