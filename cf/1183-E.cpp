#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,k,ans,c;
string s;
map<string,bool> mp;
int main()
{
    ans=0;
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    cin>>s;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
        string tp=q.front();
        q.pop();
        if(mp[tp]){
            continue;
        }
        ans+= n-tp.size();
        mp[tp]=1;
        c++;
        if(c==k){
            break;
        }
        for(int i=0;i<tp.size();i++){
            string pt=tp;
            pt.erase(pt.begin()+i);
            q.push(pt);
        }
    }
    if(c<k){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }

    return 0;
}
