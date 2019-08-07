#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int a,b;
}f[5200];
int n,m;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	int sum=n,ans=0;
	for(int i=0;i<m;i++)
    {
        cin>>f[i].a>>f[i].b;
    }

    cout<<ans<<endl;
   return 0;
}
