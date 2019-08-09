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
int n,m;
int f[maxn],a[maxn];
struct node{
    int l,r,mid,num;
}tree[maxn<<2];
void built(int x,int l,int r)
{
    tree[x]={l,r,(l+r)>>1,0};
    if(l==r){
        return ;
    }
    built(x<<1,l,tree[x].mid);
    built(x<<1|1,tree[x].mid+1,r);
}
void updata(int x,int val)
{
    ++tree[x].num;
    if(tree[x].l==tree[x].r){
        return ;
    }
    if(val<= tree[x].mid){
        updata(x<<1,val);
    }
    else{
        updata(x<<1|1,val);
    }
}
int query(int x,int num)
{
    if(tree[x].l==tree[x].r){
        return tree[x].l;
    }
    if(num<=tree[x<<1].num){
        return query(x<<1,num);
    }
    else{
        return query(x<<1|1,num-tree[x<<1].num);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=a[i];
    }
    sort(a+1,a+n+1);
    int bound=unique(a+1,a+1+n)-a;
    built(1,1,n);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(a+1,a+1+bound,f[i])-a;
        updata(1,pos);
        if(i%2){
            cout<<a[query(1, (i+1)>>1)]<<endl;
        }
    }
    return 0;
}