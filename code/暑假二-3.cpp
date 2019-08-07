#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
using namespace std;
char f[30][30];
int d[4][2]={ 1,0,0,1,-1,0,0,-1},step;
int n,m,X1,Y1,ans=0;
void dfs(int x,int y)
{
    if(f[x][y]=='#')
        return ;
    step++;
    for(int i=0;i<4;i++)
    {
        int cx=x+d[i][0];
        int cy=y+d[i][1];
        if(cx<0||cy<0||cx>=n||cy>=m)
        {
            continue;
        }
        f[x][y]='#';
        dfs(cx,cy);
    }
}
int main()
{
    while(cin>>m>>n,m!=0)
    {
        step=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>f[i][j];
                if(f[i][j]=='@')
                    X1=i,Y1=j;
            }
        }
        dfs(X1,Y1);
        cout<<step<<endl;
    }
    return 0;
}
