#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[20000];
bool juge()
{
    for(int i=1;i<n;i++)
        if(f[i-1]!=f[i])
        return 0;
    return 1;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int c;
    while(cin>>n,n!=0)
      {
          int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>f[i],sum+=f[i];
        }
        while(1)
        {
            if(juge())
            {
                break;
            }
            ans++;
            int t=f[n-1]/2;
            f[n-1]/=2;
             for(int i=n-1;i>0;i--)
            {
                f[i]+=f[i-1]/2;
                f[i-1]/=2;
                if(f[i]%2)
                    f[i]++;
            }
            f[0]+=t;
            if(f[0]%2)
                f[0]++;
        }
        cout<<ans<<" "<<f[0]<<endl;
      }

   return 0;
}
