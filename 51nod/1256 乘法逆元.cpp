#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int exgcd(int a,int b,int &x,int &y)
{
    if(!b){x=1,y=0;return a;}
    int r=exgcd(b,a%b,x,y);
    int t=x;x=y, y=t-(a/b)*y;
    return r;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int m,n,x,y;
    while(cin>>m>>n)
    {
        exgcd(m,n,x,y);
        if(x<0)
        while(x<0)
        {
            x+=n;
        }
        cout<<x<<endl;
    }
    return 0;
}
/// 拓展欧几里得
