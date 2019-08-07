#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int w[200005],ans[200000];
int vis[200005];
vector <int > f[200005];
void ini()
{
    for(int i=0;i<=n;i++)
    {
        vis[i]=0;
    }
}
void add(int x,int y)
{
    f[x].push_back(y);
    f[y].push_back(x);
}
struct node{
    int x,step;
};
void dfs(int x,int y,int step)
{
    if(step>=n-1)
        return ;
    if(x==y)
    {
        for(int i=0;i<step;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        return ;
    }
    vis[x]=1;
    for(int i=0;i<f[x].size();i++)
    {
        int j=f[x][i];
        //cout<<j<<" ";
        if(!vis[j])
        {
            ans[step]=j;
            dfs(j,y,step+1);

        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y>>w[i];
        add(x,y);
    }
    sort(w,w+n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y,t;
        cin>>x>>y;
        ini();
        //vis[x]=1;
        ans[0]=x;
        dfs(x,y,1);
    }
   return 0;
}
/*
5
1 2 2
1 3 3
3 4 3
3 5 4
3
1 5
4 2

*/
