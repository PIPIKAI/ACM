#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define INF 0x7FFFFFFF
vector <ll> f(500005);
int main()
{
    int n,m,dp,c=0,ans=0;
    cin>>n>>m;
    dp=1;
    f[0]=INF;
    for(int i=1;i<=n;i++)
    {
        ll p;
        cin>>p;
        f[i]=min(f[i-1],p);
    }
    for(int j=0;j<m;j++)
    {
        ll t;
        cin>>t;
        while(f[n]<t)
            n--;
        if(n<1)
            break;
        else
        {
            cout<< "n= "<<n<<endl;
            ans++;
            n--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
7 5

5
5
4
3
3
2
2

2
3
5
2
4
*/
