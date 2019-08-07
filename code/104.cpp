#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;
typedef long long ll;
int x[]={ -1 ,-2,-1,-2};
int y[]={2 ,1,-2,-1};
ll f[55][55];
int sum=0;
int main()
{
    int n,m,x1,x2,y1,y2;
    while(cin>>n>>m>>x1>>y1>>x2>>y2)
    {
         memset(f,0,sizeof(f));
        f[x1][y1]=1;
    for(int i=x1;i<=x2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<4;k++)
            {
                int cx=i+x[k];
                int cy=j+y[k];
                if(cx>0&&cy>0&&cx<=n&&cy<=m)
                f[i][j]+=f[cx][cy];
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<f[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<f[x2][y2]<<endl;
    }

    return 0;
}

