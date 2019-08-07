#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int > f[22];
int m,a,b,c,ca,vis[22],ans[22];
void add(int i,int a,int b,int c)
{
    if(a>b)
        swap(a,b);
    if(a>c)
        swap(a,c);
    if(b>c)
        swap(b,c);
    f[i].push_back(a),f[i].push_back(b),f[i].push_back(c);
}
void dfs(int a,int step)
{
    ans[step]=a;
    if(step>=20)
    {
        for(int i=0;i<f[a].size();i++)
        {
            int t=f[a][i];
           if(t==m)
           {
                   ca++;
                cout<<ca<<":  ";
                for(int i=1;i<=20;i++)
                    cout<<ans[i]<<" ";
                cout<<m<<endl;
                 break ;
            }

        }
        return ;

    }
    for(int i=0;i<f[a].size();i++)
    {
        int t=f[a][i];
        if(!vis[t])
        {
            vis[t]=1;
            dfs(t,step+1);
            vis[t]=0;
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int t=20;
    for(int j=1;j<=20;j++)
    {
        cin>>a>>b>>c;
        add(j,a,b,c);
    }
    while(cin>>m,m!=0)
    {
        memset(vis,0,sizeof(vis));
        ca=0;
        vis[m]=1;
        dfs(m,1);
    }
   return 0;
}
