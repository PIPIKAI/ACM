#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,mod=20181225;
const int N=2;
ll temp[N][N];
void multi(ll a[][N],ll b[][N],ll n)
{
    memset(temp,0,sizeof temp);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        for(ll k=0;k<n;k++)
            temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            a[i][j]=temp[i][j];
}
ll s[N][N];
void qpow(ll a[][N],ll n,ll m)
{
    memset(s,0,sizeof s);
    for(ll i=0;i<n;i++) s[i][i]=1;
    while(m)
    {
        if(m&1)
            multi(s,a,n);
        multi(a,a,n);
        m>>=1;
    }
     for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        a[i][j]=s[i][j];
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    ll a[N][N],ans1,ans2;
    cin>>x>>y;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        cin>>a[i][j];
    cin>>n;
    qpow(a,2,n);
    ans1=(a[0][0]*x+a[0][1]*y)%mod;
    ans2=(a[1][0]*x+a[1][1]*y)%mod;
    cout<<ans1<<" "<<ans2<<endl;
   return 0;
}
