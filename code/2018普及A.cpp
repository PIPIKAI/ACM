#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    char s[50000];
    int ans=0;
    gets(s);
    for(int i=0;i<strlen(s);i++)
        if(s[i]!=' ')
        ans++;
    cout<<ans<<endl;
    return 0;
}
