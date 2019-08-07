#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x;
	while(cin>>x,x>0.0000001)
	{
		double h=0.00;
		int i=0;
		if(x)
		for( i=2;h<x;i++)
		{
			h=h+1.0/i;
		}
		cout<<i-2<<" card(s)"<<endl;
	}
	return 0;
}
