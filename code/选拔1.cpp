#include<bits/stdc++.h>
using namespace std;
int f[1002][1002],n;
int main()
{
   ios::sync_with_stdio(false);
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>f[i][j];
    for(int i=0;i<q;i++)
    {
        int t,ans=0;
        cin>>t;
        for(int j=0;j<n;j++)
        {
           int k=lower_bound(*(f+j),*(f+j)+n,t+1)-f[j];
           if(f[j][k]>t)
               ans+=(n-k);
        }
        cout<<ans<<endl;
    }
   return 0;
}
