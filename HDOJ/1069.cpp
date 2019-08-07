#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,z;
}f[220];
int dp[220],n;
bool cmp(node a,node b)
{
    return a.x*a.y>b.x*b.y;
}
void ini()
{
     memset(f,0,sizeof(f));
     memset(dp,0,sizeof(dp));
     for(int i=0;i<n;i++)  cin>>f[i].x>>f[i].y>>f[i].z;
     int cnt=n;
     for(int i=0;i<n;i++)
     {
         f[cnt].x=f[i].x,f[cnt].y=f[i].z,f[cnt++].z=f[i].y;
         f[cnt].x=f[i].y,f[cnt].y=f[i].x,f[cnt++].z=f[i].z;
         f[cnt].x=f[i].y,f[cnt].y=f[i].z,f[cnt++].z=f[i].x;
         f[cnt].x=f[i].z,f[cnt].y=f[i].y,f[cnt++].z=f[i].x;
         f[cnt].x=f[i].z,f[cnt].y=f[i].x,f[cnt++].z=f[i].y;
     }
     n=cnt;sort(f,f+n,cmp);
     for(int i=0;i<n;i++) dp[i]=f[i].z;
}
void solve(int ca)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(f[i].x<f[j].x&&f[i].y<f[j].y)
            dp[i]=max(dp[i],dp[j]+f[i].z),ans=max(ans,dp[i]);
        }
    }
    cout<<"Case "<<ca<<": maximum height = "<<ans<<endl;
}
int main()
{
    int t=0;
    while(cin>>n,n!=0)
    {
        t++;
        ini();
        solve(t);
    }
    return 0;
}
