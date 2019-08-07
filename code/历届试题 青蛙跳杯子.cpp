#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
string s1,s2;
map<string ,int > m;
struct node
{
    string s;
    int step;
    node(string ss,int tp){    s=ss;step=tp;    }
};
queue<node> q;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>s1>>s2;
    int l=s1.size();
    q.push(node(s1,0));
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        if(t.s==s2)
            return cout<<t.step<<endl,0;
        for(int i=0;i<l;i++){
            if(t.s[i]=='*')
                for(int j=max(0,i-3);j<=min(l-1,i+3);j++){
                    string ts=t.s;
                    if(ts[j]!='*'){
                        swap(ts[j],ts[i]);
                        if(m[ts]==0){
                            m[ts]=1;
                            q.push(node(ts,t.step+1));
                        }
                    }
                }
        }
    }
    return 0;
}
