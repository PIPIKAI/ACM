#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n;
int main()
{
    std::ios::sync_with_stdio(false);
    int ca=0;
    while(cin>>n)
    {
        ll cnt=0;;
        stack<int >s;
        for(int i=1;i<=n;i++)
        {
            ll t;
            cin>>t;
            if(s.empty())
            {
                if(t!=0)
                {
                    s.push(t);
                    cnt++;
                }
            }
            else
            {
                while(!s.empty()&&s.top()>t)
                {
                    s.pop();
                }
                if(s.empty())
                {
                    if(t!=0)
                    {
                        s.push(t);
                        cnt++;
                    }
                }
                else if(t> s.top())
                {
                    cnt++;
                    s.push(t);
                }
            }
        }
        cout<<"Case "<<++ca<<": "<<cnt<<endl;
    }
    return 0;
}
