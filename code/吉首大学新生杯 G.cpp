#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m,cnt;
int f[2000];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        int zz=0;
        for(int i=1;i<=n;i++)
        {
            cin>>f[i];
            if(!f[i])
                zz++;
        }

        cnt=0;
        while(1)
        {
            if(zz==0)
            {
                cout<<cnt<<endl;
                break;
            }
            cnt= (cnt+m-1)%n;
            if(cnt==0)
                cnt=n;
            cout<<cnt<<endl;
            if(f[cnt])
                continue;
            f[cnt]=1;
            zz--;
        }
    }
    return 0;
}
