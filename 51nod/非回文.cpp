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
	char s[1050];
	cin>>n>>p>>s;

   return 0;
}

