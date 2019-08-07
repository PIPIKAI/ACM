#include<bits/stdc++.h>
using namespace std;
#define MAX 1000+7
int dp[MAX][MAX]={0};
int t[MAX][MAX]={0};
int main()
{
    string s,b;
    cin>>s>>b;
    int n=s.length(),m=b.length();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i]==b[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;

                }
            else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j]=dp[i-1][j]+1;
            else
                dp[i][j]=dp[i][j-1]+1;
        }
    }
    cout<<len-dp[len][len]<<endl;
    return 0;
}
