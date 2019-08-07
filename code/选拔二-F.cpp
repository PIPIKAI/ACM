#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    int f[200];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
        f[i]=(n-i)*f[i];
    }
    sort(f,f+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(f[i]<m)
        {
            ans++;
            m-=f[i];
        }
        else
            break;
    }
    cout<<ans<<endl;
   return 0;
}

