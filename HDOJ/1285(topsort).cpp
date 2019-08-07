#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector <int > f[600];
int d[600];
void add(int a,int b)
{
    f[a].push_back(b);
}
vector <int > ans;
priority_queue<int ,vector<int >,greater<int > > q;
void topsort()
{
     for(int i=1;i<=n;i++)  if(d[i]==0) q.push(i);
     while(!q.empty())
     {
         int t=q.top();
         q.pop();
         ans.push_back(t);
         for(int j=0;j<f[t].size();j++)
         {
             int a=f[t][j];
             d[a]--;
             if(!d[a])
                q.push(a);
         }
     }
     for(int i=0;i<n;i++)
        if(i!=n-1)
         cout<<ans[i]<<" ";
     else
        cout<<ans[i];
        ans.clear();
    for(int i=0;i<=n;i++) f[i].clear();
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	while(cin>>n>>m)
    {
       memset(d,0,sizeof d);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);
            d[b]++;
        }
        topsort();
        cout<<endl;
    }
   return 0;
}
