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
const int maxn=1e6+7;
double f[1000050]={0};
void ini(){
    for(int i=1;i<maxn;i++){
        f[i]=1.0*log(i)+f[i-1];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,ca=0,n,base;
    ini();
    cin>>t;
    while(t--){
        ca++;
        cin>>n>>base;
        cout<<"Case "<<ca<<": ";
        if(n==0){
            cout<<1<<endl;
        }
        else{
            int ans= ceil(f[n]/log(base) );
        cout<<ans<<endl;
        }
    }
    return 0;
}
