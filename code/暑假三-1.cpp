#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ch()
{

}
ll qpow(int f[],int n)
{

}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	ll x,y,a,b,c,d,n;
	ll tx,ty;
	cin>>tx>>ty>>a>>b>>c>>d>>n;
	for(ll i=0;i<n;i++)
    {
        x=(a*tx+b*ty)%20181225;
        y=(c*tx+d*ty)%20181225;
        tx=x;
        ty=y;
    }
    cout<<x<<" "<<y<<endl;
   return 0;
}
