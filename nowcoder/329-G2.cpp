#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20][20];
void init()
{
	f[0][0]=1;
	for(int i=1;i<=18;i++)
	{//len
		for(int j=0;j<10;j++)
		{// sta
			if(j==6)f[i][j]=0;
			else
            for(int k=0;k<10;k++)//link
			{
				if(k==6)continue;
				f[i][j]+=f[i-1][k];
			}
		}
	}
}
ll pos[18];
ll solve(ll x)
{
	ll c=0,cc=x;
	while(cc){
		pos[++c]=cc%10;
		cc/=10;
	}
	ll ans=0;
	pos[c+1]=0;
	for(int i=c;i>=1;i--)
	{
		for(ll j=0;j<pos[i];j++)
            ans+=f[i][j];
			if(pos[i]==6)break;
	}
	return ans;
}
int main()
{
	ll n,m;
	ios::sync_with_stdio(0);
	init();
	while(cin>>n>>m)
    {
        ll ans=m+1 -n - solve(m+1)  + solve(n);
		cout<< ans <<endl;
    }


	return 0;
}
