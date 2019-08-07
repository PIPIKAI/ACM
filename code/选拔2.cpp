#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x,y;
}f[101];
ll jj(node a)
{
   ll x=a.x*a.x+a.y*a.y;
   return x;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n;
	int a,b,c,d;
	cin>>n;
	if(n==1)
    {
        return cout<<"Yes"<<endl,0;
    }
	for(int i=0;i<n;i++)
        cin>>f[i].x>>f[i].y;
    ll j=jj(f[0]);
    for(int i=1;i<n;i++)
    {
       if(j!=jj(f[i]))
        return cout<<"No"<<endl,0;
    }
    cout<<"Yes"<<endl;
   return 0;
}
