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
int maxn=0,t[100005],f[1000005],k[100005],n,m;
int lowbit(int x){
    return (x&(-x));
}
int getsum(int x){
    int sum=0;
    while(x){
        sum+=f[x];
        x-=lowbit(x);
    }
    return sum;
}
void add(int x,int val){
    while(x<=maxn+5){
        f[x]+=val;
        x+=lowbit(x);
    }
}
int main()
{
    n=read();
    for(int i=0;i<n;i++){
        t[i]=read(); t[i]++; Max(maxn,t[i]);
    }
    mem(f,0);
    for(int i=0;i<n;i++){
        add(t[i],1);
        k[i]+= i+1 -getsum(t[i]);
    }
    mem(f,0);
    for(int i=n-1;i>=0;i--){
        add(t[i],1);
        k[i]+= getsum(t[i]-1);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll tt=k[i];
        ans+=tt*(tt+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
