#include<stdio.h>
int map[500][500];
int n,flag=0;
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
        if(map[i][j]==0)
        {
            map[i][j]=1;
            mi_gong(i,j);
        }

        else if(map[i][j]==1)
             ;
        else if(map[i][j]==3)
        {
            flag=1;
        }
    }
    return ;
}
int main()
{
scanf("%d",&n);
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
{
    scanf("%d",&map[i][j]);
}
mi_gong(0,0);
if(flag==0)
    printf("NO\n");
else
    printf("YES\n");
    return 0;
}
