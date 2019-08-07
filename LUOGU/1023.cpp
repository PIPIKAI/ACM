#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
}f[10000];
int main()
{
    int n;
    cin>>n;
    int b,s;
    cin>>b>>s;
    int cnt=0;
    while(cin>>x>>y,x!=1&&y!=1)
    {
        f[cnt].x=x;
        f[cnt++].y=y;
    }
    int jian;
    cin>>jian;

    return 0;
}
