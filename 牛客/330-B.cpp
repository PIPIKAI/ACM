#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int vis[20][20]={0};
int n,m;
void dfs(int x,int y)
{
    if(y==0)
    {
        if(x+1<n)
            cout<<'D';
        return dfs(x+1,y);
    }
    if(y==)
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    vis[0][0]=1;
    if(n%2 && m%2)
        cout<<"-1"<<endl;
    else
    {
        cout<<'D';
        for(int i)
    }
    return 0;
}
