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
ll n,a,b,c,re;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>a>>b>>c,n||a||b||c)
    {
        ll x,y,z;
        ll sum=a+b*5+10*c;
        if(sum<n)
        {
            cout<<"Hat cannot buy tea."<<endl;
            continue;
        }
        re=sum-n;
        //cout<<re<<endl;
        x= re /10;
        x= min(x,c);
        re-=10*x;
        y= re/5 ;
        y= min(y,b);
        re-= 5* y;
        z= re;
        if(z>a)
        {
             cout<<"Hat cannot buy tea."<<endl;
        }
        else
        {
            cout<<a-z<<" YiJiao, "<<b-y<<" WuJiao, and "<<c-x<<" ShiJiao"<<endl;
        }
    }
    return 0;
}
