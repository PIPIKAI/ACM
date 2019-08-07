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
ll n,m,ans=0;
ll f[100005];
ll pi[100050]={0};
void ss(int l1,int r1,int l2,int r2)
{
    ll a[100005];
    int i=l1,j=l2,tp=l1;
    while(i<=r1&&j<=r2)
    {
        if(f[i]>=f[j])
        {
            cout<<i<<" "<<j<<endl;
            a[tp++]=f[j++];

        }
        else
        {
            a[tp++]=f[i++],ans+= (r2-j+1);

        }
        ///3
        cout<<(r2-j+1)<<endl;

    }
    while(i<=r1)
        a[tp++]=f[i++];
    while(j<=r2)
        a[tp++]=f[j++];
    for(int k=l1;k<=r2;k++)
        f[k]=a[k];
}
void mersort(int l,int r)
{
    if(l>=r) return ;
    int m=(l+r)>>1;
     mersort(l,m);
     mersort(m+1,r);
     ss(l,m,m+1,r);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    mersort(0,n-1);
for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
    cout<<ans<<endl;
    return 0;
}
