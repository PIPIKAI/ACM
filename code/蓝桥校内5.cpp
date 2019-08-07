#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define pc   putchar
int n,m;
void ss(int i)
{
    pc('/');
    for(int j=0;j<(n+2*i);j++)
    pc(' ');
    pc('\\');
}
void solve1()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        pc(' ');
        ss(i);
        for(int j=0;j<(n+2*(n-i-1));j++)
        if(i==n-1)
        pc('_');
        else
        pc(' ');
        ss(i);
        cout<<endl;
    }
}
void solve2()
{
    for(int i=0;i<n;i++)
    {
        pc('|');
        for(int j=0;j<(n+2*(3*n-1));j++)
            pc(' ');
        pc('|');
        cout<<endl;
    }
}
void solve3()
{
     for(int i=0;i<3*n;i++)
    {
        for(int j=0;j<i;j++)
        pc(' ');
        pc('\\');
        for(int j=0;j<(n+2*(3*n-i-1));j++)
        if(i==n*3-1)
        pc('_');
        else
        pc(' ');
        pc('/');
        cout<<endl;
    }
}
void ini()
{
    for(int i=0;i<n;i++)
    pc(' ');
    for(int i=0;i<n;i++)
    pc('_');
    for(int i=0;i<n+2*(n);i++)
    pc(' ');
    for(int i=0;i<n;i++)
    pc('_');
    cout<<endl;

}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        ini();
        solve1();
        solve2();
        solve3();
    }
    return 0;
}

