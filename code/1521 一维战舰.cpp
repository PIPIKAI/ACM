#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
typedef long long ll;
ll f[200005];
int main()
{
	ll n,k,a,m,c=1;
	ll  sum=0,x=0;
	cin>>n>>k>>a;
	memset(f,-1,sizeof(f));
	cin>>m;
	sum=n-k*a;
	a++;
	bool flag=false;
	cin>>x;
	for(int i=x;i>0;i-=a)
	f[i]=1;
	for(int i=x;i<=n;i+=a)
	f[i]=1;
	/*for(int i=1;i<=n;i++)
	cout<<f[i]<<" ";*/
	for(int i=2;i<=m;i++)
	{
		scanf("%d",&x);
		if(f[x]==1)
		c++;
		else
		flag=1;
		if(c>sum)
		flag=1;
		if(flag)
		return cout<<i<<endl,0;
	}
	cout<<"-1"<<endl;
	return 0;
 } 

