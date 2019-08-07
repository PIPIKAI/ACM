#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2e9+7
int main()
{
    std::ios::sync_with_stdio(false);
    int a,b,c;
    while(cin>>a>>b>>c)
    {
       for(int i=1;i<=a*b*c;i++)
       {
           if(i%a==0&&i%b==0&&i%c==0)
           {
               cout<<i<<endl;
               break;
           }
       }
    }
    return 0;
}
