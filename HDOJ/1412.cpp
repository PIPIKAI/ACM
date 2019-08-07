#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    set<int >  s;
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n+m;i++)
        {
            int t;cin>>t;
            s.insert(t);
        }
        set<int>::iterator tt;
        int flag=1;
        for(tt=s.begin();tt!=s.end();tt++ )
        {
            if(flag)
            cout<<*tt,flag=0;
            else
            cout<<" "<<*tt;
        }
        cout<<endl;
        s.clear();
    }
    return 0;
}
