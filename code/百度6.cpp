#include<bits/stdc++.h>
using namespace std;
char s[100005];
int n,q,t,cnt=1,ans,f[100005][28];
int query(int a,int b)
{
	int t;
	for(int i=0;i<26;i++)
	{
	 t=f[b][i]-f[a-1][i];
		if(t!=0)
		break;
	}
	return t;
}
int main()
{
	scanf("%d",&t);cnt=1;
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d%s",&n,&q,s);
		for(int i=0;i<n;i++)
		{
			char t=s[i];
			for(int j=0;j<26;j++)
			{
				f[i+1][j]=f[i][j];
			}
			f[i+1][t-'A']++;
		}
		/*for(int i=1;i<=n;i++)
		{
			printf(" %d ",f[i][0]);
		}*/
		printf("Case #%d:\n",cnt);cnt++;
		for(int i=0;i<q;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			ans=query(a,b);
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
2
2 3
AB
1 1
1 2
2 2
8 6
ABAABCBA
1 8
2 8
4 7
4 8
5 7
5 8
*/
