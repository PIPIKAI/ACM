#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m,k,T;
struct node
{
    ll x,y;
};
node f[150];
ll area(int i,int j,int k)
{
    return abs(f[i].x*f[j].y+f[j].x*f[k].y+f[k].x*f[i].y-f[i].x*f[k].y-f[j].x*f[i].y-f[k].x*f[j].y);
}
int main()
{
    std::ios::sync_with_stdio(false);
    scanf("%d",&T);
    while(T--)
    {
        mem(f,0);
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%lld%lld",&f[i].x,&f[i].y);
        vector <ll> ans;
        for(int i=0;i<n-2;i++)
            for(int j=i+1;j<n-1;j++)
                for(int k=j+1;k<n;k++)
                    ans.push_back(area(i,j,k));

        nth_element(ans.begin(),ans.begin()+n*(n-1)*(n-2)/6-k,ans.end());
        ll cc=ans[n*(n-1)*(n-2)/6-k];
        if (cc%2==0)
        printf("%lld.00\n",cc/2);
        else
        printf("%lld.50\n",cc/2);
    }
    return 0;
}
