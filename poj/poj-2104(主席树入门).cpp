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
const int maxn = 1e5+7;
int n,m,f[maxn];
vector<int> v;
struct  node
{
    int l,r,val;
}tree[maxn<<2];
int get_id(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void updata(int x,int l,int r,int val){
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int t,i=0;i<n;i++){
        cin>>f[i];
        v.push_back(f[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;i++){

    }
    for(int i=0,l,r,k;i<m;i++){

    }
    return 0;
}