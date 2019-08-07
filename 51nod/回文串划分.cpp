#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e8
int dp[5050];
bool f[5000][5002];
bool ishh(char *s,int l,int r)
{
    for(int i=l;i<=(r+l)>>1;i++)
    {
        if(s[i]!=s[r+l-i])
            return 0;
    }
    return 1;
}
void chu(int l,int r)
{
    while(l<=r)
    {
        f[l][r]=1;++l;--r;
    }
}
int main()
{
   ios::sync_with_stdio(false);
	char s[5050];
	cin>>s;
	for(int i=0;i<5001;i++)
        dp[i]=inf;
    memset(f,0,sizeof f);
	int len=strlen(s);
	for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(!f[i][j])
                {
                    if(ishh(s,i,j))
                    {
                       chu(i,j);
                    }
                }
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            int x=f[i][j];
            if(x)
            dp[j]=min(dp[j],dp[i-1]+1);
        }
    }
    cout<<dp[len-1]<<endl;
   return 0;
}
