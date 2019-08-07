#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i;
    while(cin>>n)
          {
    ll sum=0,x=0;
   string s;
   cin>>s;
   for(int i=0;i<n;i++)
   {
       if(s[i]=='x'&&s[i+1]=='x'&&s[i+2]=='x')
       sum++;
   }
    cout<<sum<<endl;
          }
    return 0;
}
