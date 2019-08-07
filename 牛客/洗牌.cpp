#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
int a[108],b[108],c[208],n,k,j;
void solve()
{
    int t[208],cnt=0;
    for(int i=0;i<n;i++)
    {
        t[cnt++]=a[i];
        t[cnt++]=a[i+n];
    }
    for(int i=0;i<2*n;i++)
       a[i]=t[i];
}
void dis()
{
    for(int i=0;i<2*n;i++)
    {
        if(i==2*n-1)
           cout<<a[i]<<endl;
        else
        cout<<a[i]<<" ";
    }
}
void ini()
{
    for(int i=1;i<=k;i++)
        {
            solve();
        }
        dis();
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<2*n;i++)cin>>a[i];
        ini();
    }
    return 0;
}
