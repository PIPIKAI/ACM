#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char f[51][51];
int vis [51][51];
int d[4][2]={1,0,0,1,-1,0,0,-1};
struct node
{
    int w;
    char c;
}w[28];
int n,m;
bool flag=0;
bool cmp(node a,node b)
{
    return a.w>b.w;
}
void dfs(int x,int y,char c,int be,int ed,int step)
{
    if(flag==1)
        return ;
    if(vis[x][y]&&x==be&&y==ed&&step>=4)
    {
        flag=1;
        return ;
    }
    if(vis[x][y])
        return ;
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int cx=x+d[i][0];
        int cy= y+d[i][1];
        if(f[cx][cy]==c)
        {
            dfs(cx,cy,c,be,ed,step+1);
        }
    }
}
int juge(char c)
{
    flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c==f[i][j])
                {
                    memset(vis,0,sizeof(vis));
                    dfs(i,j,c,i,j,0);
                    if(flag==1)
                        return 1;
                }
        }
    }
     return 0;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            w[c-'A'].w++;
            w[c-'A'].c=c;
            f[i][j]=c;
        }
    sort(w,w+26,cmp);
    for(int i=0;i<26;i++)
    {
        if(w[i].w<=3)
            return cout<<"No"<<endl,0;
        else{

            if(juge(w[i].c))
            {
                return cout<<"Yes"<<endl,0;
            }
        }
    }
    cout<<"No"<<endl;
   return 0;
}
/*
4 3
CBC
CCC
CCC
BBB
*/
