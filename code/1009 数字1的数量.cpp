#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll i=n,ans=0,q=1;
    while(i)
    {
    	int d=i;
    	d%=10;
    	if(d==1)
    	ans=ans+(i/10)*q+(n%q+1);
    	else if(d==0)
    	ans+=(i/10)*q;
    	else
    	ans+=(1+i/10)*q;
    	i/=10;
    	q*=10;
	}
    cout<<ans<<endl;
    return 0;
}
