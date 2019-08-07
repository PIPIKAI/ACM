#include<iostream>
#include<algorithm>
using namespace std;
int f[2000];
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
    }
    sort(f+1,f+n+1);
    for(int i=1;i<=n;i++)
        ans+=(n-i+1)*f[i];
    cout<<ans<<endl;
    return 0;
}
