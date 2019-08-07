#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		while(t--)
	{
		int f[2000];
		int n;cin>>n;
		for(int i=0;i<n;i++)
		cin>>f[i];
		sort(f,f+n);
		for(int i=0;i<n;i++)
		if(i!=n-1)
		cout<<f[i]<<" ";
		else
		cout<<f[i];
		cout<<endl;
	}
	}
	return 0;
 } 
