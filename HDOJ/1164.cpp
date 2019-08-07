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
int p[65550],vis[65550],cnt;
const int N =65540 ;
vector <int >ans;
void ini()
{
    mem(p,0);
    cnt=1;
    mem(vis,0);
    for(int i=2;i<N;i++)
    {
    if(!vis[i]) p[cnt++]=i;
        for(int j=1;j<cnt&&i*p[j]<N;j++)
        {
            vis[i*p[j]]=1;if(i%p[j]==0) break;
        }
    }
}
bool solve(int n)
{
     for(int i=1;i<cnt;i++)
        {
            int t=p[i];
            if(n==1)
                return 1;
            if(t>n)
            {
                return 0;
            }
            if(n%t==0)
            {
                n/=t;
                ans.push_back(t);
                return solve(n);
            }
        }
}
int main()
{
    std::ios::sync_with_stdio(false);
    ini();
    while(cin>>n)
    {
        ans.clear();
       if(solve(n))
       {
           for(int i=0;i<ans.size();i++)
            if(i==0)
            cout<<ans[i];
           else
            cout<<"*"<<ans[i];
            cout<<endl;
       }
       else
        cout<<n<<endl;
    }
    return 0;
}
