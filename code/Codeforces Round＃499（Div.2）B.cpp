#include<bits/stdc++.h>
using namespace std;
int p[105],f[105],cc,cnt;
bool cmp(int a,int b)
{
    return a>b;
}
void ini()
{
    cc=0, cnt=0;
    for(int i=0;i<=100;i++)
    {
        if(p[i]!=0)
            f[cnt++]=p[i];
    }
    sort(f,f+cnt,cmp);
}
int main()
{
    memset(p,0,sizeof p);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        p[t]++;
    }
for(int k=1;k<=100;k++)
{
    ini();
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<n;j++)
        {
               if(f[i]>=k)
            {
                f[i]-=k;
                //cout<<k<<endl;
                cc++;
            }
            else
            {
                break;
            }
        }

    }
    if(cc>=n)
    ans=max(ans,k);
}
    cout<<ans<<endl;

    return 0;
}

