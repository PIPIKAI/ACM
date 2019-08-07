#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{

    int i,j,k,l,r,n;
    while(cin>>n)
{
    int f[200][200];
    ll t=1;
    for(i=0;i<(n)/2;i++)
    {
        for(j=i;j<n-i-1;++j)
        {
            f[i][j]=t;
            t++;
        }
        for(j=i;j<n-i;++j)
        {
            f[j][n-i-1]=t;
            t++;
        }
        for(j=n-i-2;j>i;j--)
        {
            f[n-i-1][j]=t;
            t++;
        }
        for(j=n-i-1;j>=i+1;j--)
        {
            f[j][i]=t;
            t++;
        }
    }
    if(n&1)
        f[n/2][n/2]=t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",f[i][j]);
        cout<<endl;
    }
    cout<<endl;
}
    return 0;
}
