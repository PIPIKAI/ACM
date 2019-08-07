#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,k;
string s;
int f[300]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    cin>>s;
    int to=1;
    for(int i=1;i<=s.length();i++)
    {
        if(s[i]==s[i-1])
            to++;
        else
        {
            f[s[i-1]] +=(to/k);
            to=1;
        }
    }
    int pt= 'a',ans=0;
    for(int i= pt ;i<=26+pt;i++)
    {
        ans=max(f[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
