#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
int f[2000];
int j[2000];
int n,m,flag=1;
using namespace std;
typedef long long ll;
using namespace std;
void memr(int x,int y)
{
    int t=min(f[x],f[y]);
    int b=max(f[x],f[y]);
    if(f[x]!=y)
    {
        for(int i=1;i<=n;i++)
    {
        if(f[i]==b)
            f[i]=t;
    }
    }
    else if(f[x]==y)
    {
        flag=0;
    }

}
int main()
{

    while(cin>>n>>m,n!=0)
    {
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            memr(x,y);
        }
       /* for(int i=1;i<=n;i++)
            cout<<f[i]<<" ";*/

        for(int i=1;i<=n-1;i++)
        {
            if(f[i]!=f[i+1])
            flag=0;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
