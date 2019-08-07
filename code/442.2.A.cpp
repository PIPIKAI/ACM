#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int f[3000];
    ll sum=0,b=0,ans=0;
    int n;
    cin>>n;
    for(int i=0;i<n/2;i++)
        {
            int t;
            cin>>t;
            f[i]=t;

        }
        sort(f,f+n/2);
        for(int i=0;i<n/2;i++)
        {
            int t=f[i];
            ans+=abs(i*2+1-t);
            b+=abs((i+1)*2-t);
        }
    cout<<min(b,ans)<<endl;
    return 0;
}
