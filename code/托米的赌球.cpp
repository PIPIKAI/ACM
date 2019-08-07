#include<bits/stdc++.h>
using namespace std;
int ans1[150];
int ans2[150];
int b[]={100,50,20,10,5,2,1};
int z[]={50,20,10,5,2,1};
int main()
{
    int t;
    int f[200][2];
    while(cin>>t)
    {
    	int x,y;
    	memset(f,0,sizeof(f));
    //	memset(ans,0,sizeof(ans));
		while(t--)
		{
			cin>>x>>y;
			int a;
			for(int i=0;i<7;i++)
			{
				 a=x/b[i];
				 x=x%b[i];
				 //ans[b[i]]=a;
				 cout<<a<<" ";
			}
			for(int i=0;i<6;i++)
			{
				 a=y/z[i];
				 y=y%z[i];
				 cout<<a<<" ";
			}
			cout<<endl;
		}
    }
    return 0;
}
