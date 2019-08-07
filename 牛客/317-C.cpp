#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n;
int a[3030],f[3030][4888];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
   if(a[1]<=a[n]) return cout<<-1<<endl,0;
   f[1][ a[1]^a[n] ] =1;
   for(int i=2;i<n;i++)
    if(a[i] > a[n] && a[i] < a[1])
   {
       for(int j=4888 ; j>=1; j --)
       {
           if(  f[i][ j^a[i] ] && a[i] > j )
            f[i][j]=1;
       }
   }
   for(int i=4888;i>=0;i--)
    if(f[n][i]) return cout<<i<<endl,0;
   cout<<-1<<endl;
    return 0;
}
