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
int f[maxn];
struct node
{
    int l,r;
};
struct  TREE
{
    int l,r;
    int lazy,sum;
    void push_up(int lazyp){
        lazy+=lazyp;
        sum+=lazyp;
    }
}tree[maxn<<2];
void built(int x,int l,int r)
{
    tree[x]=TREE{l,r,0,0};
    if(l==r){
        tree[x].sum=0;
    }
    else{
        int mid=(l+r)>>1;
        built(x<<1,l,mid);
        built(x<<1|1,mid+1,r);
    }
}
void update(int x,int l,int r,int val){
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    
    return 0;
}