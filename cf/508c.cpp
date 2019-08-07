#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
ll a=0,b=0;
priority_queue <int ,vector <int >,less<int > >q1;//大的优先级高
priority_queue <int ,vector <int >,less<int > >q2;//大的优先级高
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        q1.push(t);
    }
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        q2.push(t);
    }
    while(!q1.empty()||!q2.empty())
    {
        int t=q1.top(); int tt=q2.top();
        if(q1.empty())
        {
            q2.pop();
            int t=q2.top();
            b+=t;
            q2.pop();
        }
        else if(q2.empty())
        {
            a+=q1.top();
            q1.pop();
            q1.pop();
        }
        else
        {
            if(t>tt)
            {
                q1.pop();
                if(q1.empty())
                {
                    q2.pop();
                }
                else
                {
                    a+=t;
                t=q1.top();
                if(t>tt)
                    q1.pop();
                else
                    b+=tt,q2.pop();
                }

            }
            else{
                q2.pop();
                if(q2.empty())
                {
                    q1.pop();
                }
                else{
                     tt=q2.top();
                if(tt>t)
                    b+=tt,q2.pop();
                else
                    q1.pop();
                }

            }

        }
    }
    cout<<a-b<<endl;
    }

    return 0;
}
