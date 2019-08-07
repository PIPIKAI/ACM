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
ll n,m;
ll bl(ll x,ll y)
{
    return (x*y)/2;
}

ll wl(ll x,ll y)
{
    return (x*y)/2+((x*y)%2==0?1:0);
}
ll qwl(ll x1,ll y1,ll x2,ll y2 )
{
    return wl(x2,y2)-wl(x2,y1)-wl(x1,y2)+wl(x1,y1);
}
ll qbl(ll x1,ll y1,ll x2,ll y2)
{
    return bl(x2,y2)-bl(x2,y1)-bl(x1,y2)+bl(x1,y1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        ll ans1=bl(n,m),ans2=wl(n,m);
        ll x1,y1,x2,y2,x3,x4,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll minx=max(x1,x3),miny=max(y1,y3),maxx=min(x2,x4),maxy=min(y2,y4);
        ans1=ans1+qbl( x1, y1, x2, y2)-qwl( x3, y3, x4, y4);
        ans2=ans2+qwl( x1, y1, x2, y2)-qbl( x3, y3, x4, y4);;
        if(maxx<minx||maxy<miny)//最小的中的最大的还比最大的中的最小的要小就相离，否则相交
		{
            ;
		}
		else//如果相交的话，就将其重叠的面积减去就OK了！
		{
		    ans1+=qbl( x1, y1, x2, y2);
			ans2+=qwl( x1, y1, x2, y2);
			sum=(maxx-minx)*(maxy-miny);
			printf("%lld\n",s-sum);
		}
        ll w=qwl(x1,y1,x2,y2);
        ll b=qbl(x1,y1,x2,y2);
        cin>>x1>>y1>>x2>>y2;
    }

    return 0;
}
