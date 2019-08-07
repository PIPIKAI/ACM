#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
	{
		int  f[1500]={0};
		bool flag=false;
		for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
		sort(f,f+n);
		int l=0,r,ans=0;
		for(int i=0;i<n;i++)
		{
			int s=m-f[i];
			int j=upper_bound(f,f+n,s)-f;
			j--;
			if(j==i)
			j--;
			if(j>=0&&j<n&&(f[i]+f[j]<=m))
			{
				flag=true;
				ans=max(ans,f[i]+f[j]);
			}
		} 
		if(flag)
		printf("%d\n",ans);
		else
		printf("NONE\n");
	}
	return 0;
}
