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
 ll T,n,k,f[100000];
 int p[65550],vis[65550],cnt;
const int N =65540 ;
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
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>T;
   // while(T--)
    {
        ll d=0,p;
       // cin>>n>>k;

        for(ll i=1;i<=10000000000;i++)
        {
            d=0;
            for(int j=1;j<=i;j++)
            {
                 if(i%j==0)
               {
                   d++;
               }
            }
          cout<<i<<"  :"<<d<<" "<<endl;;
          system("pause");
        }
    }
    return 0;
}
