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
int n,m;
double C(double x,double n)
{
    int t=n;
    double s=1;
    if(t==0)
        return 1;
    while(t--)
    {
        if(x-t>0)
        s*=(x-t);
    }
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T,ca=0;
    cin>>T;
    while(T--)
    {
        double n,m,k;
        ca++;
        cout<<"case : "<<ca<<" ";

        cin>>n>>m>>k;/// 40 9 5
        double ans=0;
         for(double i=k;i<=n;i++)
         {
             ans+= i*1.0 *  ( C(n-m, i-k)*C( m , k ) )*1.0/ ( C( n , i) );
             cout<<ans<<endl;
         }
         cout<<ans<<endl;
    }
    return 0;
}
