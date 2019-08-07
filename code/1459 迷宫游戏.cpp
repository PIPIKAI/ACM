#include<bits/stdc++.h>
using namespace std;
int f[600][600];
int w[600];
int n , m, start, e;
int main()
{
    memset(f,-1,sizeof(f));
    cin>>n>>m>>start>>e;
    for(int i=0;i<n;i++)
    { int x;
        cin>>x;
        w[i]=x;
    }
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        f[x][y]=z;
        f[y][x]=z;
    }

    return 0;
}
