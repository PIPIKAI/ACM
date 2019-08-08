#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1005000];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>f[i];
        int flag=0,ans=0;
        for(int i=1;i<n;i++)
        {
            if(f[i]<f[i-1])
            {
                if(flag)
                    ans++;
                flag=0;
            }
             if(f[i]>=f[i-1])
            {
                flag=1;
            }
        }
        cout<<ans<<endl;
    }
   return 0;
}
