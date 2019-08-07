#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int f[200][200],n;
void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(f[i][j]>f[i][k]+f[k][j])
                    f[i][j]=f[i][k]+f[k][j];
}
int main()
{
    memset(f,inf,sizeof(f));
    int i,j,q;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        cin>>f[i][j];
        floyd();
    cin>>q;
    for(i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<f[x][y]<<endl;
    }


}
