#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2;
ll mod=1e8;
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
   ll a[N][N],n,m;
   a[0][0]=1;a[0][1]=1;
   a[1][0]=1;a[1][1]=0;
   cin>>n>>m;
   ll k=__gcd(n,m);
   if(k<=2){
       cout<<1<<endl;
   }
   else{
    qpow(a,2,k-2);
    cout<<(a[0][0]+a[1][0])%mod<<endl;
   } 
   return 0;
}
