#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
string s1,s2;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>s1>>s2)
    {
        int pre=-1,ans=0,l=s1.size();
        for(int i=0;i<l;i++)
               if(s1[i]!=s2[i])
                  if(pre==-1)
                    pre=i;
                  else
                    ans+=(i-pre),pre=-1;
        cout<<ans<<endl;
    }
    return 0;
}
