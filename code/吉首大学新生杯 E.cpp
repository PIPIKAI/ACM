#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int a,b;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        int cnt=0;
        string s;
        int t=a+b;
        if(t==0)
        {
            cout<<0<<endl;
            continue;
        }

        while(t!=0)
        {
            char c= t%10 + '0';
            cnt++;
            s = c+s ;
            t/=10;
            if(cnt%3==0&&t!=0)
            {
                s= ',' + s;
                cnt=0;
            }

        }
        cout<<s<<endl;
    }
    return 0;
}
