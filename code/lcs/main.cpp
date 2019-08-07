#include <iostream>
#include<cstring>
using namespace std;
void solve();
int f[1000][1000];
void solve()
          {
               string a,b,ans;
               cin>>a>>b;
               int n,m,i,j;
               n=a.length();
               m=b.length();
                for( i=1;i<=n;i++)
                {
                    for( j=1;j<=m;j++)
                    {
                        if(a[i-1]==b[j-1])
                           f[i][j]=f[i-1][j-1]+1;
                        else
                            f[i][j]=max(f[i-1][j],f[i][j-1]);
                    }
                }

            return ;
          }
int main()
{
        solve();
    return 0;
}
