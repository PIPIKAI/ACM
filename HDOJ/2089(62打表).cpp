#include<bits/stdc++.h>
using namespace std;
int f [1000001];
void  biao()
{
	for(int i=0;i<1000001;i++)
	{
		int j=i;
		while(j)
		{
			if(j%10==4||j%100==62)
			{f[i]=1;break;}
			j/=10;
		}
	}
}
int main()
{
    int n,m;
    memset(f,0,sizeof(f));
    biao();
    while(cin>>n>>m,n!=0&&m!=0)
    {
    	int ans=m-n+1;
    	for(int i=n;i<=m;i++)
    	if(f[i])
    	ans--;
    	cout<<ans<<endl;
    }
    return 0;
}
