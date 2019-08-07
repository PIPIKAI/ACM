#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
int f[100050][20]={200000};
void RMQ(){
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            if(i+(1<<j)-1<=n){
                f[i][j]=min(f[i][j-1],f[i+(1<<(j-1)) ][j-1]);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        f[i][0]=read();
    }
    RMQ();
    while(m--){
        int l,r,k;
        l=read();r=read();
        k=log2(r-l+1);
        cout<<min(f[l][k],f[r-( 1<<k) +1][k])<<" ";
    }
    return 0;
}
