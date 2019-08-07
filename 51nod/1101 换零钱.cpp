#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf =1e9+7;
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
ll n,m;
ll f[100050]={1};
ll cc[13]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();
    for(ll i=0;i<13;i++)
        for(int j=cc[i];j<=n;j++)
        {
            f[j] = (f[j] + f[j-cc[i]])%inf;
        }
    cout<<f[n]<<endl;
    return 0;
}
