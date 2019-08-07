#include <iostream>
#include<cstring>
using namespace std;
void solve()
          {
              int f[1002][1003];
                memset(f,0,sizeof(f));
               string a,b,ans;
               cin>>a>>b;
               int m=a.size(),n=b.size();
               int i,j;
               for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
               {
                   if(a[i-1]==b[i-1])
                    f[i][j]=f[i-1][j-1]+1;
                    else
                        f[i][j]=max(f[i-1][j],f[i][j-1]);
               }
          }
