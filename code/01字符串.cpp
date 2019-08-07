#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define  for_(i,a,b) for(int i=a;i<b;i++)
#include<queue>
int f[12]={0};
ll n;
ll comebie()
{
    ll s=0;
    for_(i,0,10)
    {
        s=s*10+i;
    }
    return s;
}
bool juge(ll s)
{
    if(s%n==0)
        return true;
    else
        return false;
}
void solve()
{
    cin>>n;
    int be=1;
    for_(i,0,6)
    {
        if(be>n){f[i]=1;;break;}
        be*=10;
    }
    //cout<<be<<endl;
    for(int i=)
    while(!juge(comebie()))
    {
      f[be++]=
    }
}
int main()
{
    solve();
    return 0;
}
