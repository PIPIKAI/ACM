#include<stdio.h>
char map[500][500];
int n,m,flag=0,min_way=0,val,end_x,end_y;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void mi_gong(int t,int k)
{
    int i,j;
    for(int p=0;p<4;p++)
    {

        i=t+dir[p][0];
        j=k+dir[p][1];
        if(i>=n||j>=n||i<0||j<0)
            continue;
        if(map[i][j]=='-')
        {
            map[i][j]='#';
            min_way++;
            if()
            else
            mi_gong(i,j);
        }
        else if(map[i][j]=='E')
        {

            flag=1;
        }
    }
    return ;
}
int main()
{
    int i,begin_X,begin_y;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
    scanf("%s",map[i]);
for( i=0;i<=n;i++)
    for(int j=0;j<m;j++)
{
    if(map[i][j]=='S')
    {
        begin_X=i;
        begin_y=j;
    }
    if(map[i][j]=='E')
    {
        end_x=i;
        end_y=j;
    }

}
mi_gong(begin_X,begin_y);
if(flag==0)
    printf("-1");
else
    printf("%d\n",min_way);
    return 0;
}
