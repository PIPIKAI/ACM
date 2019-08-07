#include<stdio.h>
int n,sum=0;
void dfs(int step,int add,int temp,int zheng_fu)
{
    if(step==9&&temp)
    add+=temp*zheng_fu;
    if(step==9&&add==n)
        sum++;
    if(step==9)
        return ;
    dfs(step+1,add+temp*zheng_fu,step+1,1);
    dfs(step+1,add+temp*zheng_fu,step+1,-1);
    dfs(step+1,add  , temp*10+step+1,zheng_fu);
}
int main()
{
    scanf("%d",&n);
    dfs(1,0,1,1);
    printf("%d\n",sum);
    return 0;
}
