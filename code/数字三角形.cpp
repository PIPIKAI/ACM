#include<iostream>
#include<algorithm>
using namespace std;

int D[101][101],Max=0,n;
int fuck_angel(int i,int j )
{
    if(i==n-1)
    return D[i][j];
    int x=fuck_angel(i+1,j);
    int y=fuck_angel(i+1,j+1);

    return max(x,y)+D[i][j];
}
int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
            cin>>D[i][j];
    }
    cout<<fuck_angel(0,0);

    return 0;
}
