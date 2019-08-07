#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        double wei=x*log10(double (x));
        double k=  wei-floor(wei);
         printf("%d\n",(int )pow(10.0,k));
    }
   return 0;
}
