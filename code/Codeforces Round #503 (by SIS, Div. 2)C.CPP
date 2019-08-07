#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int z,w;
};
node f[3004];
int pe[3005];
int c[3005];
ll inf =1e7;
bool cmp(node a,node b)
{
    return a.w>b.w;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	ll ans=inf;
	while(cin>>n>>m)
    {
        memset(pe,0,sizeof pe);
        memset(ans,0,sizeof ans);
        for(int i=1;i<=n;i++)
        {
            cin>>f[i].z>>f[i].w;
        }
        sort(f+1,f+n+1,cmp);
        int sum;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;i<=n;i++) pe[j]=0;sum=0;
            for(int j=1;j<=n;j++) c[j]=0;
            for(int j=1;j<=n;j++)
            {
               if(f[j].z==1) pe[1]++;
               else
               {
                   if(pe[f[j].z]+1>=i)
                    {
                        sum+=f[j].w;
                        pe[1]++;
                        c[j]=1;
                    }
                    else
                        pe[f[j].z]++;
               }
            }
            for(int j=n;j>=1;j--)
            {
                if(f[j].z!=1&&c[j]==0&&pe[1]<i)
                {
                    c[j]=1,sum+=f[j].w;
                    pe[1]++;
                }
            }
            if(pe[1]>=i)
                ans=min(ans,sum);
        }
        cout<<ans<<endl;
    }
   return 0;
}


