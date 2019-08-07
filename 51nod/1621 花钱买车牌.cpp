#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,k;
ll f[20];
priority_queue <int ,vector <int >,less<int > >q;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    ffr(i,0,n)
    {
        char c=getchar();
        f[c-'0']++;
    }
    ffr(i,0,10)
    {
        ll cnt=0;
        ffr(j,0,10)
        {
            cnt+= abs(i-f[j])
        }
    }
    cout<<f[5];
    return 0;
}
