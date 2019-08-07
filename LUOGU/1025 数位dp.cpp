#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,ans=0,f[205][8];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;i++)
    {
        f[i][1]=1;
    }
	for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            f[i][j]=f[i-1][j-1]+f[i-j][j];
        }
    }
	cout<<f[n][k]<<endl;
   return 0;
}
