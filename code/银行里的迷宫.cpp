#include<stdio.h>
int flag=0,n,m,ans;
char map[501][501];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}
};
void  dfs(int x,int y,int time,int step)
{
    int i,cx,cy;
    if(time==0)
    {
    flag=1;
        return ;
    }
    for(i=0;i<4;i++)
    {
        cx=x+dir[i][0];
        cy=y+dir[i][1];

        if(cx<0||cy<0||cy>=n||cx>=m)
            continue;
            map[x][y]='W';
            if(map[cx][cy]=='T'||map[cx][cy]=='t')
            {
                dfs(cx,cy,time-2,step+2);
            }

            else if(map[cx][cy]=='W'||map[cx][cy]=='w')
                continue;
            else if(map[cx][cy]=='A'||map[cx][cy]=='a')
            {
                flag=2;
                ans=step+1;
                return ;
            }
            else
            {
                dfs(cx,cy,time-1,step+1);
            }
    }
    return ;

}

int main()
{
    int time ;

    scanf("%d%d%d",&n,&m,&time);
    int i;
    for(i =0;i<n;i++)
    {
        scanf("%s", map[i]);
    }

    dfs(0,0,time,1);
   if(flag==2)
    printf("%d",ans);
   else
    printf("Oh my god!");
    return 0;
}
