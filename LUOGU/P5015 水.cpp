#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    ll ans=0;
    char cc='0';
    while(cc!='\0')
    {
        cc=getchar();
        if(cc!=' ')
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
