#include<iostream>
using namespace std;
int f[100][100], t[100][100];
int main()
{
    int n,i,j;
    cin>>n;
    for( i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        {
            cin>>f[i][j];
        }
    for(i=n;i>1;i--)
        for(j=1;j<i;j++)
    {
        int x=max(f[i][j],f[i][j+1]);
         f[i-1][j]=x+f[i-1][j];
    }
    cout<<f[1][1]<<endl;
    return 0;
}
