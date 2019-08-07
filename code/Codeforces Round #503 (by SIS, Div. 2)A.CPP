#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,h,a,b,k;
	while(cin>>n>>h>>a>>b>>k)
    {
        for(int i=0;i<k;i++)
        {
            int x,y,o,p;
            cin>>x>>y>>o>>p;
            if(x==o)
            {
                cout<<abs(y-p)<<endl;
            }
            else
            {
                if((y>=a&&y<=b)||(p>=a&&p<=b))
                {
                     int ans=abs(x-o)+ abs(y-p);
                     cout<<ans<<endl;
                }
               else{
                int ans=abs(x-o)+min(abs(y-a)+abs(p-a),abs(y-b)+abs(p-b));
                cout<<ans<<endl;
               }
            }
        }
    }
   return 0;
}
