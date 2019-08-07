#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1005],hole[1005];
int fin(int x)
{
    hole[x]++; return f[x];
}
int mer(int x,int y)
{
    x=fin(x);
    if(hole[x]==2)
        return x;
    else
    {
        mer(x,f[x]);
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,h,a,b,k;
	while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>f[i];
        }
        for(int i=1;i<=n;i++)
        {
            memset(hole,0,sizeof hole);
            cout<<mer(i,f[i])<<" ";
        }
        cout<<endl;
    }
   return 0;
}

