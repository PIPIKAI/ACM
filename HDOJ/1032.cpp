#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int ac4(int x)
{
    int c=1;
    while(x>1)
    {
    if(x&1)
        x=x*3+1;
    else
        x=x/2;
        c++;
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        int temp=0;
        int nn=n,mm=m;
        if(n>m) swap(n,m);

        for(int i=n;i<=m;i++)
        {
            int c=ac4(i);
           temp=max(temp,c);
        }
        cout<<nn<<" "<<mm<<" "<<temp<<endl;
    }
    return 0;
}
