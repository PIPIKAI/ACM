#include<bits/stdc++.h>
using namespace std;
struct aa
{
	int x,y,vis;
}f[5005];
bool cmp(struct aa a,struct aa b)
{
	if(a.x==b.x)
	return a.y<b.y;
	
	return a.x<b.x;
}
int main()
{
    int t,n,u,d;
    while(cin>>t)
    {
    	while(t--)
    	{
			memset(f,0,sizeof(f));
			int n,ans=0;
			cin>>n;
			for(int i=0;i<n;i++)
				cin>>f[i].x>>f[i].y; 
			sort(f,f+n,cmp);
			for(int i=0;i<n;i++)
			{
				if(!f[i].vis)
				{
					f[i].vis=1;
					ans++;
					int w=f[i].y;
					for(int j=i+1;j<n;j++)
					{
						if(f[j].vis==0 && w<=f[j].y)
						{
							f[j].vis=1;
							w=f[j].y;
						}
					}
				}			
			}
			cout<<ans<<endl;	
		}
    }
    return 0;
}
