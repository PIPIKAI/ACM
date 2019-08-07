#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll f[20000];
int main()
{
    ll n,ans=0,maxn;
    int i,j;
    cin>>n>>maxn;
    for(i=0;i<n;i++)
        cin>>f[i];
    sort(f,f+n);
    for(i=0,j=n-1;i<=j;j--)
    {
        ll t=f[i]+f[j];
        if(t>maxn)
            ans++;
        else
        {
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

