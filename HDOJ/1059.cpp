#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int a[7];
int dp[500000];
int main()
{
    std::ios::sync_with_stdio(false);
    int ca=0;
    while(1)
    {
        ca++;
        memset(dp,0,sizeof dp);
        int f[500000],cnt=0;
        int flag=1,sum=0;
        for(int i=1;i<=6;i++)
        {
            cin>>a[i];
            int t=1;
            sum+=a[i]*i;
            if(a[i]!=0)
                {
                    flag=0;
                    while(a[i]>t)
                    {
                        f[cnt++]=t*i;
                        a[i]-=t;
                        t<<=1;
                    }
                    f[cnt++]=i*a[i];
                }
        }
        if(flag)
            break;
        cout<<"Collection #"<<ca<<":"<<endl;
        if(sum%2==1)
        {
            cout<<"Can't be divided."<<endl<<endl;continue;
        }
        sum/=2;
        for(int i=0;i<cnt;i++)
        {
            //cout<<f[i]<<" ";
            for(int j=sum;j>=f[i];j--)
                dp[j]=max(dp[j],dp[j-f[i]]+f[i]);
        }
        if(dp[sum]==sum)
            cout<<"Can be divided."<<endl;
        else
        cout<<"Can't be divided."<<endl;
        cout<<endl;
    }
    return 0;
}
