#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m,k;
int f[10050][20];
bool juge(int i)
{
    int b1,b2;
    ll sum=0;
    for(b1=0;b1<n;b1++)
    {
        for(b2=0;b2<n;b2++)
            if(b1!=b2&&b2!=i&&b1!=i)
                break;
        if(b1!=b2 && b2!=i && b1!=i)
                break;
    }
    for(int j=0;j<k;j++)
        sum += (f[b1][j]-f[i][j])*(f[b2][j]-f[i][j]);
        return sum<0 ? true : false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int ans=0;
        bool flag=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
                cin>>f[i][j];
        if(n>k+2)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(juge(i))
            {
                cout<<1<<endl;
                flag=1;
                for(int j=0;j<k;j++)
                    cout<<f[i][j]<<" ";
                    cout<<endl;
                break;
            }
        }
        if(!flag)
            cout<<"0"<<endl;
    }
    return 0;
}
