#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    {
        string s;
        int flag=0;
        cin>>s;
       for(int i=1;i<n;i++)
       {
           if(s[i]<s[i-1])
           {
               s.erase(i-1,1);
               flag=1;
               break;
           }
       }
       if(!flag)
        s.erase(n-1,1);

       cout<<s<<endl;
    }
    return 0;
}
