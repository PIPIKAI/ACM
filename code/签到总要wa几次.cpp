#include <bits/stdc++.h>
using namespace std;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {char c = getchar(); int x = 0, f = 1;
while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;}
#define read(x) x=read()
const int maxn = 2000;
int f[maxn], n, m, x;
bool k[maxn];
int main() {
    ios::sync_with_stdio(false);
    int T;
    read(T);
    while (T--) {
        read(m);read(n);read(x);
        int ans = 0, res = m;
        for (int i = 0; i < n; i++) {
           read(f[i]);
            k[i]=0;
        }
        sort(f, f + n);
        int flag=0;
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < n; j++) {
                if(i%f[j]==0){
                    if(k[j]){
                        ans--;
                        k[j]=0;
                    }
                    else{
                        if(!flag)
                        res--;
                    }
                }
                else if(k[j]!=1){
                   if(!flag){
                        k[j]=1;
                        ans++;
                        res--;
                   }
                }
                if(res==0){
                    flag=1;
                }
            }
        }
       printf("%d %d\n",res,ans);
    }
    return 0;
}
