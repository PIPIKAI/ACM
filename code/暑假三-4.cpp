#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[108];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        for(int j=a;j<=b;j++)
            f[j]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(f[i]==0)
            ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;i++)
    {
        if(f[i]==0)
           cout<<i<<" ";
    }
   return 0;
}
