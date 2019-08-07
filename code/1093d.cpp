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
int a,b,c,d;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>a>>b>>c>>d)
    {
        c=max(0,c);
        d=max(0,d);
    if(d<=0&&c<=0)
    {
        cout<<"No"<<endl;return 0;
    }
    while(1)
    {
        if(a<=0)
        {
            cout<<"Yes"<<endl;
            break;
        }
        if(b<=0)
        {
            cout<<"No"<<endl;
            break;
        }
        a-=d;
        b-=c;
    }
    }

    return 0;
}
