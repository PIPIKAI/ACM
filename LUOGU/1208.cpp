#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int a,b;
}f[5200];
bool cmp(node a,node b)
{
    return a.a<b.a;
}
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
    sort(f,f+m,cmp);
    for(int i=0;i<m;i++)
    {
        if(sum-f[i].b>=0)
        {
            sum-=f[i].b;
            ans+=(f[i].a*f[i].b);
        }
        else{
            ans+=(f[i].a*sum);
            break;
        }
    }
    cout<<ans<<endl;
   return 0;
}
