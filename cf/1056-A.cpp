#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int f[109]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    int n,T;
    cin>>n;T=n;+
    while(T--)
    {
        int m;cin>>m;
        while(m--)
        {
            int t;
            cin>>t;
            f[t]++;
        }
    }
    for(int i=1;i<=100;i++)
            if(f[i]==n)
            cout<<i<<" ";
    cout<<endl;
    return 0;
}
