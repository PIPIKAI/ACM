#include<stdio.h>
char map[5001][1001];
int n,m,sum=0;
int movee[4][2]={1,0,0,1,-1,0,0,-1};

void dfs(int x,int y)
{
    int i,cx,cy;
    map[x][y]='.';
    for(i=0;i<4;i++)
    {
        cx=x+movee[i][0];
        cy=y+movee[i][1];
        if(cx>=n||cx<0||cy<0||cy>=m)
            continue;
        if(map[cx][cy]=='#')
        {
            map[x][y]='.';
            dfs(cx,cy);
        }

    }
}
int main()
{

    int i,j;
    scanf("%d%d",&n,&m);
    for( i=0;i<n;i++)
        scanf("%s",map[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {

            if(map[i][j]=='#')
            {
                dfs(i,j);
                sum++;
            }

        }
    }
    printf("%d",sum);
    return 0;
}

