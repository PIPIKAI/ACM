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
#define mid (l+r)/2
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 2e5+7;
int n,m;
struct node{
    int pos,val;
}f[maxn];
int sum[maxn<<2];
int ans[maxn];
void push_up(int x){
    sum[x]=sum[x<<1]+sum[x<<1|1];
}
void built(int x,int l,int r){
    if(l==r){
        sum[x]=1;return ;
    }
    built(x<<1,l,mid);
    built(x<<1|1,mid+1,r);
    push_up(x);
}
void update(int x,int l,int r,int pos,int val){
    if(l==r){
        sum[x]=0;
        ans[l]=val;
        return ;
    }
    if(sum[x<<1] >= pos) update(x<<1,l,mid,pos,val);
    else update(x<<1|1,mid+1,r,pos- sum[x<<1],val);
    push_up(x);
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        built(1,1,n);
        for(int i=0;i<n;i++){
            cin>>f[i].pos>>f[i].val;
        }
        for(int i=n-1;i>=0;i--){
            update(1,1,n,f[i].pos+1,f[i].val);
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
            i==n ? cout<<'\n' : cout<<" ";
        }
    }
    return 0;
}