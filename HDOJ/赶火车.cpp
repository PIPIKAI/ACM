#include<bits/stdc++.h>  
typedef long long ll;
using namespace std;
double n,m,y;
#define mem(x, y) memset(x,y,sizeof(x))
int a[20],b[20],f[10500],vis[1050];
ll res;
void dfs(int x,int sta,int s)
{
    if(x==0){f[s]++;return ;}
    for(int i=0;i<m;i++)
    {
        if(vis[i]<sta)
        {
            vis[i]++;
            s+=b[i];
            dfs(x-1,sta,s);
            s-=b[i];
            vis[i]--;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>y;
        mem(a,0);mem(b,0);mem(f,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                memset(vis,0,sizeof(vis));
                dfs(j,j,a[i]);
            }
        }
       double ans=0;
       for(int i=1;i<10000;i++)
       {
           res+=f[i];
           if(!f[i])continue;
           cout<<f[i]<<endl;
       }
       for(int i=1;i<10000;i++)ans+=(f[i]*i*1.0)/res;
       cout<<ans<<endl;
        ans<=y ?cout<<"Go"<<endl : cout<<"Wait"<<endl;
    }
    return 0;
} // name
