#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,u,d;
    while(cin>>t)
    {
    	while(t--)
    	{
		int f[205];
    	memset(f,0,sizeof(f));
    	int n;cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		if(x%2)
    		x++;
    		if(y%2)
    		y++;
    		if(x>y) swap(x,y);
    		x/=2,y/=2;
    		for(;x<=y;x++)
    		f[x]+=10;
		}
    		int ans=0;
		for(int i=0;i<=200;i++)
		ans=max(ans,f[i]);
		cout<<ans<<endl;
		}
		
    }
    return 0;
}
