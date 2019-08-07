#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,y;
int f[100][100],b[100][100],ans[101][101]={0};
int ss(int aa,int bb)
{
    int s=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            s+=b[i][j]*f[aa+i][bb+j];
        }
    }
    return s;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>f[i][j];
    cin>>x>>y;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        cin>>b[i][j];
    for(int i=0;i<n-x+1;i++)
    {
        for(int j=0;j<m-y+1;j++)
        {
            ans[i][j]=ss(i,j);
        }
    }
    for(int i=0;i<n-x+1;i++)
    {
        for(int j=0;j<m-y+1;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

   return 0;
}
