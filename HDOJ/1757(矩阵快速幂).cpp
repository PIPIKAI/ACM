#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10;
ll n,mod, k[10];
ll temp[N][N];
void multi(ll a[][N],ll b[][N],ll n)
{
    memset(temp,0,sizeof temp);
    for(ll i=0;i<n;i++)
       for(ll k=0;k<n;k++)
         for(ll j=0;j<n;j++)
            if(a[i][k])
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
    ll a[N][N],ans;
    while(cin>>n>>mod)
    {
        ans=0;
        memset(a,0,sizeof a);
        memset(k,0,sizeof k);
        if(n<10){
            cout<<n%mod<<endl;
            continue;
        }
        for(int i=0;i<10;i++)
            cin>>a[0][i],k[i]=9-i;
        for(int i=1;i<10;i++)
            a[i][i-1]=1;
        qpow(a,10,n-9);
        for(int i=0;i<10;i++)
            ans=(ans+a[0][i]*k[i])%mod;
        cout<<ans<<endl;
    }
   return 0;
}
