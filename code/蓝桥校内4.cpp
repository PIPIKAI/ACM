#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    int ans=0;
    cin>>s;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
        {
            s[i]='*';
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
