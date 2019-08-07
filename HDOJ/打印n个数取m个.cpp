#include<bits/stdc++.h>
using namespace std;
int m,n;
void combin(int *f,int step,int *sum)
{
	if(step<=0)
	{
		for(int i=0;i<m;i++)
		cout<<sum[i]<<" ";
		cout<<endl;
		return ;
	}
	for(int i=step;i<=n;i++)
	{
		sum[step]=f[i];
		combin(f,n+1, m,step,sum);
	}
}
int main()
{
	while(cin>>n>>m)
	{
		int f[500],sum[500];
		for(int i=1; i<=n;i++) f[i]=i;
		combin(f,m,sum);
	}
	return 0;
}
