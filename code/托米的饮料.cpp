#include<bits/stdc++.h>
using namespace std;
int f[150][150],n;
void dis()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<f[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    memset(f,-1,sizeof(f));
    cin>>n;
    int ans=n;
    for(int i=n;i--;)
    {
        int x,y;
        cin>>x>>y;
        if(x!=y)
        f[x][y]=1;
    }
    //dis();
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        for(int j=1;j<=n;j++)
        {
            if(f[j][i]==1)
                flag=1;
        }
        if(flag)
            ans--;
    }
    cout<<ans<<endl;
    return 0;
}

