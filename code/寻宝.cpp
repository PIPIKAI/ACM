#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k;
int step[30][2];
char str[1005][1005];
int di[1005][1005][4];// 0 shang, 1 xia ,2 zuo ,3 you
int dii[100005][2];
void init()
{
    int i,j;
    memset(di,-1,sizeof(di));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(str[i][j]=='#')
                di[i][j][0]=di[i][j][2]=-1;
            else
            {
                di[i][j][0]=di[i-1][j][0]+1;
                di[i][j][2]=di[i][j-1][2]+1;
            }
        }
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=m-1;j>=0;j--)
        {
            if(str[i][j]=='#')
                di[i][j][1]=di[i][j][3]=-1;
            else
            {
                di[i][j][1]=di[i+1][j][1]+1;
                di[i][j][3]=di[i][j+1][3]+1;
            }
        }
    }
}
int dfs(int x,int y)
{
    for(int i=0;i<k;i++)
    {
       if(di[x][y][dii[i][0]]<dii[i][1])
        return 0;
        else
        {
            if(dii[i][0]==0)
                x-=dii[i][1];
            else if(dii[i][0]==1)
                x+=dii[i][1];
            else if(dii[i][0]==2)
                y-=dii[i][1];
            else if(dii[i][0]==3)
                y+=dii[i][1];
        }
    }
    return 1;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            str[i][j]=c;
        if(c<='Z'&&c>='A')
            step[c-'A'][0]=i,step[c-'A'][1]=j;
        }
    }
    init();
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int z;
        char ch;
        cin>>ch>>z;
        if(ch=='N')
        {
            dii[i][0]=0;
            dii[i][1]=z;
        }
        if(ch=='S')
        {
            dii[i][0]=1;
            dii[i][1]=z;
        }
        if(ch=='E')
        {
            dii[i][0]=3;
            dii[i][1]=z;
        }
        if(ch=='W')
        {
           dii[i][0]=2;
            dii[i][1]=z;
        }
    }
    int is=0;
    for(int i=0;i<27;i++)
    {
        if(step[i][0]!=0&&step[i][1]!=0)
        if(dfs(step[i][0],step[i][1]))
        {
            is=1;
            char cc='A'+i;
            cout<<cc;
        }
    }
    if(!is)
        cout<<"no solution"<<endl;
    return 0;
}

