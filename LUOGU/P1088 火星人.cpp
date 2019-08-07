#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[10002];
int n;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int m,c=0;
   cin>>n>>m;
   for(int i=0;i<n;i++) cin>>f[i];
   do
   {
       if(c==m)
       {
           for(int i=0;i<n;i++)
            cout<<f[i]<<" ";
           break;
       }
       c++;
   }while(next_permutation(f,f+n));
   return 0;
}


