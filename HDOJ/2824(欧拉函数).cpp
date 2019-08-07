#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
const int  maxn=3000010;
ll n,m;
ll f[maxn];
void ini()
{
     for(int i=2;i<maxn;i++){
        if(!f[i])
        for(int j=i;j<maxn;j+=i){
            if(!f[j]) f[j]=j;
            f[j]=f[j]/i*(i-1);
        }
        f[i]+=f[i-1];
     }
}
int main()
{
    std::ios::sync_with_stdio(false);
    ini();
    int a,b;
    while(cin>>a>>b)
    {
        cout<<f[b]-f[a-1]<<endl;
    }
    return 0;
}
