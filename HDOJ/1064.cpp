#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   double ans=0;
	for(int i=0;i<12;i++)
    {
        double t;
        cin>>t;
        ans+=t;
    }
    printf("$%.2lf\n",ans/12);
   return 0;
}
