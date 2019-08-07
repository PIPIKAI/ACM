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
const int maxn=2e5+10;
int  a[maxn],ans[maxn],g[maxn],vis[maxn];
int main()
{
    int n;
    cin>>n;
    int maxx=0,cnt=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxx)maxx=a[i];
        sum+=a[i];
    }
    sum-=maxx;
    for(int i=0;i<n;i++){
        if(a[i]==maxx)g[cnt++]=i+1;
    }
    if(cnt==2&&n>2&&sum==maxx){
        cout<<2<<endl;
        cout<<g[0]<<" "<<g[1]<<endl;
        return 0;
    }
    else if(cnt>3)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        cnt=0;
        for(int i=0;i<n;i++){
            if(i==g[0]-1)continue;
            if(sum-a[i]==maxx){
                if(!vis[i+1])ans[cnt++]=i+1,vis[i]=1;
            }
            if(sum-a[i]==a[i]){
                if(!vis[g[0]])ans[cnt++]=g[0],vis[g[0]]=1;
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
