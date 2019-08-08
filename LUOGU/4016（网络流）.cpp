#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
int f[maxn],mp[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        mp[i]=i+1;
    }
    mp[n]=1;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        sum+=f[i];
    }
    cout<<sum/n<<endl;
    
    return 0;
}