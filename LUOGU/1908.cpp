#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[40002],c[40002],b[40002],f[40002];
int n,ans=0;
void sor(int l ,int r,int k,int d)
{
    int i,j;
    for( i=l;i<=r;i++)  a[i]=f[i];
    for( i=k ; i<=d;i++)  b[i]=f[i];
    int cnt=l;
    i=l,j=k;
    while(i<=r&&j<=d)
    {
        if(a[i]<=b[j])
            c[cnt++]=a[i++];
        else
            c[cnt++]=b[j++],ans=ans+r-i+1;
    }
    while(j<=d)
        c[cnt++]=b[j++];
    while(i<=r)
        c[cnt++]=a[i++];
    for(i=l;i<=d;i++)
        f[i]=c[i];
}
void mer(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mer(l,m);
        mer(m+1,r);
        sor(l,m,m+1,r);
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>f[i];
	mer(0,n-1);
    cout<<ans<<endl;
   return 0;
}
