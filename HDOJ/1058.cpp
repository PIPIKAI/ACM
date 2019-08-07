#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[6000];
void biao()
{
	int a=1,b=1,c=1,d=1;
	f[1]=1;
	for(int i=2;i<=5842;i++)
	{
		f[i]=min(min(2*f[a],3*f[b]),min(5*f[c],7*f[d]));
		if(f[i]==f[a]*2) a++;
		if(f[i]==f[b]*3) b++;
		if(f[i]==f[c]*5) c++;
		if(f[i]==f[d]*7) d++;
	}
}
int main()
{
	ll x;
	string ou;
	biao();
	while(scanf("%lld",&x),x)
	{
		ou="th";
		if(x%100!=12&&x%10==2) ou="nd";
		if(x%100!=11&&x%10==1)	ou="st";
		if(x%100!=13&&x%10==3)	ou="rd";	
		printf("The %lld",x);
		cout<<ou;
		printf(" humble number is %lld.\n",f[x]); 
	}
	
	return 0;
}
