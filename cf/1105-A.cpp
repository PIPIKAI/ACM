#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int ans1,ans2,n;
int f[105];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        ans1=inf;
        mem(f,0);
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            f[t]++;
        }
        for(int i=1;i<=100;i++)
        {
            int sum=0;
            for(int j=1;j<=100;j++)
            {
                if(j==i || !f[j])
                    continue;
                sum = sum + f[j]* min( min(abs(j-i) ,abs(j-i-1)),abs(j-i+1));
            }
           /// cout<<i<<": "<<sum<<endl;
            if(sum<ans1)
            {
                ans1=sum;
                ans2=i;
            }
        }
        cout<<ans2<<" "<<ans1<<endl;
    }
    return 0;
}
