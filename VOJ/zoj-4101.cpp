#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline ll read() {
    char c = getchar(); ll x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
#define read(x) x=read()
const int maxn=1e5+7;
ll x,y,nowx,nowy,p,q,sum,flag;
ll n,m;
ll f[maxn];
ll  mp[maxn];
int main()
{
    ll T;
    read(T);
    while(T--){
        ll begin_=maxn,end_=0;
        ll ans=0;
        nowx=0;
        nowy=0;
        mem(mp,0);
        read(n),read(x),read(y);
        for(ll i=1,t;i<=n;i++){
            read(t);f[i]=t;
            begin_=min(begin_,t);
            end_=max(end_,t);
            mp[t]++;
            nowx+= (i*t);
            nowy+= (i*t*t);
        }
         p=(nowx-x),q=(nowy-y);
         if(p==0 && q==0){
            for(int i=begin_;i<=end_;i++){
                if(mp[i])
                ans=ans+ ( mp[i] -1 )*mp[i] /2;
            }
            ans*=2;

         }
        else if(p==0 || q==0 || (p!=0 && q%p)){
            ans=0;
        }
        else {
            for(ll i=1;i<=n;i++){
                ll aj=(q/p)-f[i];
                if(aj==f[i])
                    continue;
                if(p%(f[i]-aj)==0){
                    ll j= i- p/(f[i]-aj);
                    if(j>=1 && j<=n && aj==f[j])
                        ans++;
                }
            }
        }
        printf("%lld\n",ans/2);

    }
    return 0;
}
