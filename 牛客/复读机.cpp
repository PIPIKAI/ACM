#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int ans[2000];
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    mem(ans,0);
    cin>>n>>m;
    string s;
    int p;
    cin>>p>>s;
    for(int i=1;i<m;i++)
    {
        string ts;
        int tp;
        cin>>tp>>ts;
        if(ts!=s)
            ans[tp]++;
        s=ts;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ans[i])
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
