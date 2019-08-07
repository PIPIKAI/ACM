#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int f[1006][1006];
int v[1006][1006];
int main()
{
    int x,y,n,q,i,j,k;
    int mx=0,my=0;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        int l;
        cin>>x>>y>>l;
        f[x][y]=l;
    }
    for(i=1;i<=1000;i++)
    {
        for(j=1;j<=1000;j++)
        {
            v[i][j]=v[i-1][j]+v[i][j-1]+f[i][j]-v[i-1][j-1];
        }
    }
    for(i=1;i<=q;i++)
    {
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        if(lx>rx)
            swap(lx,rx);
        if(ly>ry)
            swap(ry,ly);
        cout<<v[rx][ry]+v[lx-1][ly-1]-v[rx][ly-1]-v[lx-1][ry]<<endl;

    }
    return 0;
}
