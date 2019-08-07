#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100005];
int main()
{
    ll n,m;
    while(cin>>n>>m>>s)
    {
       if((n-1)*m<s)
        cout<<"NO"<<endl;
       else
       {
           for(int i=0;i<m;i++)
           {
               if(s>n-1)
               {
                   s-=(n-1);
               }
               if(s<=n-1)
               {

               }
           }
       }
    }
    return 0;
}

