#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[60];
int vis[60];
int n,sum,ans;
bool dfs(int len,int tar,int step,int pre)
{
    if(len==tar)
        {
            len=0;
            step++;
            pre=0;
        }
    if(step==sum/tar&&len==0)
            return 1;
    for(int i=pre;i<n;i++)
    {
        if(!vis[i]&&f[i]+len<=tar)
        {
            if(i>0&&!vis[i-1]&&f[i-1]==f[i])
                continue;
                vis[i]=1;
                if(dfs,tar,step+1,0)
                vis[i]=0;
                vis[i]=1;
                if(dfs(len+f[i],tar,step,i+1))
                {
                    return 1;
                }
                else
                {
                    vis[i]=0;
                    int ss=tar-len;
                    if(f[i]==ss||ss==tar)
                        return 0;
                }
        }
    }
        return 0;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);

	while(cin>>n,n!=0)
    {
        sum=0;
        for(int i=0;i<n;i++) cin>>f[i],sum+=f[i];
        sort(f,f+n);
	if(f[0]==f[n-1])
        {
             cout<<f[0]<<endl;
        }
        else
        {
            for(int i=f[n-1];i<=sum;i++)
            {
                for(int j=0;j<=n;j++)
                    vis[j]=0;
                if(sum%i)
                    continue;
                if(dfs(0,i,0,0))
                {
                    cout<<i<<endl;
                    break;
                }

            }
        }

    }

   return 0;
}
