#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    int ans=0,to=0,p=0,now=0;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='G')
            now++,to++;
        else
        {
            p=now;
            now=0;
        }
        ans=max(ans,p+now+1);
    }
    cout<<min(ans,to)<<endl;
    return 0;
}
