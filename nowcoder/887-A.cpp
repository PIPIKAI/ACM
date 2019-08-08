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
bool juge(string s){
    int len=s.size();
    string tp=s;
    for(int i=0;i<len;i++){
        char c=tp[0];
        tp.erase(tp.begin(),tp.begin()+1);
        tp+=c;
        if(tp <s){
            return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        n=s.size();
        for(int i=0,pos=0;i<n;233){
            string tp,add;
            pos=i;
            for(int j=i+1;j<=n;j++){
                tp=s.substr(pos,(j-pos));
                if(juge(tp)){
                    i=j;
                    add=tp;
                    //cout<<tp<<endl;
                }
            }
            ans.push_back(add);
        }
        for(int i=0;i<ans.size();i++){
            if(i!=ans.size()-1){
                cout<<ans[i]<<" ";
            }else{
                cout<<ans[i]<<endl;
            }
        }
        ans.clear();
    }
    return 0;
}
