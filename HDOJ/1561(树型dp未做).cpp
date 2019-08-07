#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int f[251][251];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   while(cin>>n>>m,n!=0&&m!=0)
    {
        memset(d,0,sizeof d);
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a!=0)
            d[i]++;
            f[i][a]=b;
        }
       for(int i=0;i<=200;i++)
       {
           sort(f[i].begin(),f[i].end(),cmp);
       }

       while(!q.empty())
       {

       }
       for(int i=0;i<=200;i++)
       {
           if(f[i].)
       }
    }
   return 0;
}

