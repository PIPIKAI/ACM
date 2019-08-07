#include<stdio.h>
int smap[4][4],sum=9999999;
int flag=0;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}
};
void swap(int *a,int *b)
{
    int t=*a;*a=*b;*b=t;
}
int right(int (*map)[4])
{
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(map[i][j]!=smap[i][j])
                return 0;
        return 1;
}
void dfs(int (*map)[4],int step,int x,int y,int rx,int ry)
{

    if(right(map))
    {
        sum=sum<step?sum:step;
        flag=1;
        return ;
    }
    if(step>81)
        return ;
    int i,cx,cy,j;

    for(i=0;i<4;i++)
    {
        cx=x+dir[i][0];
        cy=y+dir[i][1];
        if(cx>3||cx<1||cy>3||cy<1)
        continue;
        if(cx==rx&&cy==ry)
            continue;
        swap(&map[x][y],&map[cx][cy]);
       /* for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
    printf("\n");*/
        dfs(map,step+1,cx,cy,x,y);
    }

}
int main()
{
    int i,j,x,y,map[4][4];
    char t;
    char a[10],b[10];
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
        {
            scanf("%1c",&t);
            if(t>='0'&&t<='9')
            map[i][j]=t-'0';
            else
                map[i][j]=0;
        }
scanf("\n");
for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
        {
            scanf("%1c",&t);
            if(t>='0'&&t<='9')
            smap[i][j]=t-'0';
            else
            {
                x=i,y=j;
                smap[i][j]=0;
            }

        }
        dfs(map,0,x,y,-1,-1);
        if(flag)
        printf("%d",sum);
        else
            printf("-1");

    return 0;
}
