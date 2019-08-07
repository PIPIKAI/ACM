#include<bits/stdc++.h>
using namespace std;
int a[20];
int dp[20][2];
int dfs(int pos,int pre,int sta,bool limit)
{
    if(pos==-1) return 1;
    if(limit==false && dp[pos][sta]!=-1)
        return dp[pos][sta];
    int up= limit ? a[pos]:9;
    int temp=0;
    for(int i=0;i<=up;i++)
    {
        if(pre==6 && i==2)   continue;
        if(i==4)    continue;
        temp+=dfs(pos-1 , i , i==6 ,limit && i==a[pos]);
    }
    if(limit==0)
        dp[pos][sta]= temp;
    return temp;
}
int solve(int x)
{
    int pos=0;
    while(x!=0)
    {
        a[pos++]=x%10;
        x/=10;
    }
    dfs(pos-1,-1,0,true);
}
int main()
{
    int le,ri;
    memset(dp,-1,sizeof dp);
    while(~scanf("%d%d",&le,&ri),le!=0||ri!=0)
    {
        cout<<solve(ri)-solve(le-1)<<endl;
    }
    return 0;
}
