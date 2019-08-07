#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,flag=0,ans=9999999;
map< string ,bool > vis;
struct node
{
    string s;
    int step;
};
string s;
string as="2012";
queue <node > q;
bool juge(string ss)
{
    for(int i=0;i+4<=n;i++){
            string cc=ss.substr(i,4);
            if(cc==as)
                return 1;
        }
    return 0;
}
void bfs()
{
    node ss;
    int sum=0;
    ss.s=s;
    vis[s]=1;
    ss.step=0;
    q.push(ss);
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        if(juge(t.s))
        {
            ans=min(ans,t.step);
            flag=1;
            return ;
        }
        string ts=t.s;
        for(int i=0;i<n-1;i++)
        {
            swap(t.s[i+1],t.s[i]);
            if(!vis[t.s])
            {
                t.step=t.step+1;
                vis[t.s]=1;
                q.push(t);
                t.step-=1;
            }
            t.s=ts;
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   cin>>n>>s;
   bfs();
   if(flag)
    cout<<ans<<endl;
   else
    cout<<"-1"<<endl;
   return 0;
}
