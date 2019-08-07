#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
set<double > s;
int n,m,a,b;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>m>>n>>a>>b;
       for(int i=a;i<a+n;i++)
        for(int j=b;j<b+m;j++)
       {
           double t=(double)j*log2(1.0*i);
            s.insert(t);

       }
        cout<<s.size()<<endl;
    return 0;
}
