#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 2e5+7;
int n,m;
int f[maxn];
string s,t;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    int i=n-1,j=m-1;
    while(i>=0){
        if(s[i]==t[j]){
            f[j]=i;
            j--;
        }
        i--;
    }
    f[m]=n;
    int ans=f[0];
    for(int i=0,j=0;i<n;i++){
        if(s[i]==t[j]){
             ans=max(ans, f[j+1]-i-1);
             j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}