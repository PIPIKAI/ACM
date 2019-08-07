#include<bits/stdc++.h>
using namespace std;
char f[51][51];
int ma[51][51];
int ans[3000];
int c[12][4]={
    1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,
};
int m,n;
int d[4][2]={-1,0,1,0,0,-1,0,1,};
void bian(int a,int b)
{
    for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(ma[i][j]==a)
                ma[i][j]=b;
}
void find(int x,int y)
{
    if(x>=n||y>=m||x<0||y<0)
        return ;
    for(int i=0;i<4;i++)
    {
        int cx=x+d[i][0],cy=y+d[i][1];
        if(cx>=n||cy>=m||cx<0||cy<0)
        continue ;
        int j=f[cx][cy]-'A';
        int k=f[x][y]-'A';
        int p;
        if(i%2) p=i-1;
        else p=i+1;

        if(c[k][i]==1&&c[j][p]==1&&ma[x][y]!=ma[cx][cy])
        bian(max(ma[x][y],ma[cx][cy]),min(ma[x][y],ma[cx][cy]));
    }
}
int main()
{
    while(cin>>n>>m,n>0)
    {
        int sum=0;
        memset(ans,0,sizeof(ans));
        int ju=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            cin>>f[i][j];
            ma[i][j]=ju;
            ju++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
          find(i,j);
          ju++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[ma[i][j]]++;
        for(int i=0;i<=n*m;i++)
           if(ans[i])
            sum++;
           cout<<sum<<endl;
    }
    return 0;
}
