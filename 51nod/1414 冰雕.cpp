#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
int f[20050],ans;
int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        f[i]=read();
        ans+=f[i];
    }
    for(int i=3;i<=n/2;i++){
        if(n%i){
            continue;
        }
        for(int j=1;j<=n/i;j++){
                int tp=0;
                for(int k=j;k<=n;k+=(n/i)){
                    tp+=f[k];
                }
            ans=max(ans,tp);
        }

    }
    cout<<ans<<endl;
    return 0;
}
