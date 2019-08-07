#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[10002];
int n,m,ans;
int gcd(int a,int b)
{
    return !b? a :gcd(b,a%b);
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   ans=0;
   cin>>n>>m;
   for(int i=n;i<=m;i+=n)
   {
       if(n*m%x==0&&n==gcd(x,n*m/x))
          ans++;
   }
   cout<<ans<<endl;
   return 0;
}



