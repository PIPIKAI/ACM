#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
int f[5050],p[200][200]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        mem(p,0);
        int j=0;
    if(m<n-1)
    {
        cout<<"-1"<<endl;continue;
    }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b>>f[i];
        if(p[a][b]==0)
            j++;
        p[a][b]=p[b][a]=1;
    }
    if(j<n-1)
   {
    cout<<"-1"<<endl;continue;
    }
    sort(f+1,f+m+1);
    int k=j-n+1;
    int ans=inf;
    for(int i=1;i<=k+1;i++)
    {
        ans=min(abs(f[i]-f[i+n-2]),ans);
    }
    cout<<ans<<endl;
    }
    return 0;
}
