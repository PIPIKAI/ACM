#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    int x,y;
    cin>>x>>y;
    cout<<(x+y)*(x-y)/4<<endl;
    return 0;
}
