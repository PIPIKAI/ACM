#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cx[8]={1,0,-1,0,-1,-1,1,1};
int     cy[8]={0,1,0,-1,-1,1,1,-1};
int f[1010][1010]={0};
string ans="UNK";
int flag=0;
void dfs(int x,int y,int l)
{
    int i,j;
    for( i=0;i<4;i++)
    {
        int bx,by;
        int k=1;
        for( j=1;j<=10;j++)
        {
            bx=x+cx[i]*j,by=y+cy[i]*j;
            if(f[bx][by]!=l)
                {
                    k=0;
                    break;
                }
        }
        if(k)
            {
                flag=1;
                return ;
            }
    }
}
void dis()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<f[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int anss;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,l;
        cin>>x>>y;
        if(i&1)
            l=f[x][y]=2;
        else
            l=f[x][y]=1;
        dis();
        if(flag==0&&i>=9)
        {
            dfs(x,y,l);
            if(flag)
            {
                if(i&1)
                ans="HtBest";
                else
                ans="WHZ";
                anss=i;
            }
        }
    }
    if(flag==0)
    anss=m;
    cout<<ans<<" "<<anss<<endl;
   return 0;
}

