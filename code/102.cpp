#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
struct aa
{
    int vis,sor,out;
};

typedef struct aa  ff;
bool cmp(ff a,ff b)
{
    return a.sor<b.sor;
}
int main()
{
    ll n;
    while(cin>>n)
    {
        int son=0;
        ff f[2000];
        memset(f,0,sizeof(f));
      for(int i=1;i<=n;i++)
      {
          int t;
          cin>>t;
          if(f[t].vis==0)
          {
              f[t].vis++;
              f[t].sor=i;
              f[t].out=t;
              son++;
          }
          else if(f[t].vis==1)
          {
              f[t].sor=i;
              f[t].out=t;
          }
      }
      sort(f,f+2000,cmp);
      cout<<son<<endl;
      for(int i=0;i<2000;i++)
      {
          if(f[i].vis==1)
            cout<<f[i].out<<" ";
      }
      cout<<endl;
    }
    return 0;
}
