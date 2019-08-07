#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {int x,y;};
int v[1100][1100],f[1100][1100];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>f[i][j];

    cin>>q;
    for(int i=0;i<q;i++)
    {
        node a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        qur(a,b);
    }
   return 0;
}
