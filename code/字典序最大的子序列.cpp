#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100009];
int dp[100009];
int main()
{

    string a,b;
    while(cin>>a)
{
    reverse(a.begin(),a.end());
        memset(f,0,sizeof(f));
        memset(dp,0,sizeof(dp));
    for(int i=0;i<a.size();i++)
    {
        f[i]=a[i]-'a';
    }

    dp[0]=f[0];
    int len=0;
    for(int i=1;i<a.size();i++)
        if(dp[len]<=f[i])
            dp[++len]=f[i];
        else
        {
            int j=lower_bound(dp,dp+len,f[i])-dp;
            if(j==len)
            dp[j]=f[i];
        }
        for(int i=len;i>=0;i--)
        {
            char t='a'+dp[i];
            cout<<t;
        }

    cout<<endl;
}
    return 0;
}
