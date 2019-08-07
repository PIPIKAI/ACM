#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int dp[300][50]={0},sum[300][300]={0};
int intread() {int x;scanf("%d",&x);return x;}
string s,ss[50];
int p,k,n;
bool chc(int l,int r)
{
    string ts=s.substr(l,r-l+1);
    for(int i=1;i<=n;i++)
    {
        if(ts.find(ss[i])==0)
            return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>p>>k;
    s+='8';
    for(int i=1;i<=p;i++)
    {
        string t;cin>>t;
        s+=t;
    }
    cin>>n;int m=s.length()-1;
    for(int i=1;i<=n;i++)
        cin>>ss[i];


    for(int i=m;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            sum[j][i]=sum[j+1][i];
            if(chc(j,i))
                sum[j][i]++;
        }
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<sum[i][j]<<" ";
        cout<<endl;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        {

        }
    }
    return 0;
}
