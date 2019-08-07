#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,k,book[5000000]={0},a[50],f[50],ans=0;
int ispri(ll x)
{
    for(ll i=2;i*i<=x;i++)
        if(!x%i)
        return 0;
    return 1;
}
void dfs(int step)
{
    if(step>=k)
    {
        ll tp=0;
        for(int i=0;i<k;i++)
        {
           // tp+=f[i];
            cout<<f[i]<<" ";
        }
        cout<<endl;
        if(ispri(tp))
            ans++;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(book[a[i]]==0)
        {
            f[step]=a[i];
            book[a[i]]=1;
            dfs(step+1);
            book[a[i]]=0;
        }
    }
}
int main()
{
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
