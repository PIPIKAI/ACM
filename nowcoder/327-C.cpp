#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
int n,m;
int f[1050];
double ans=0;
int main()
{
    std::ios::sync_with_stdio(false);
    int n=-1,t;
    char c;
    while(1)
    {
        c=getchar();
        if(c>='0'&& c<='9')
        f[++n]=c-'0';
        else
        break;
    }
    if(n==0)
    {
        if(f[0]==1)
        {
            cout<<1<<endl;
            return 0;
        }
        else if(f[0]<=3)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(f[i]==0)
        continue;
            //cout<<n-i<<" "<<f[i]<<endl;
        int k=n-i;
         ans+= (double)k* log2(10)+log2(f[i]);

    }
    cout<<(int)ans<<endl;
    return 0;
}
