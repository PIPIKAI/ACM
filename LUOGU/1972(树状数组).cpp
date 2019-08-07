#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,q;
const int maxn=5e5+7,N=1e6+7;
int a[maxn],f[maxn]={0},ans[maxn]={0},vis[N]={0};
struct node{
    int l,r,pos;
}ask[maxn];
int lowbit(int x){
    return x&(-x);
}
int query(int x){
    ll ans=0;
    while(x){
        ans+=f[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,int val){
    while(x<=maxn){
        f[x]+=val;
        x+=lowbit(x);
    }
}
bool cmp(node a,node b){
    return a.r<b.r;
}
int main()
{
    scanf("%d",&n);
    for(int j=1;j<=n;j++){
        scanf("%d",a+j);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&ask[i].l,&ask[i].r);
        ask[i].pos=i;
    }
    sort(ask+1,ask+1+q,cmp);
    int next=1;
    for(int i=1;i<=q;i++){
        for(int j=next;j<=ask[i].r;j++){
            if(vis[a[j]]){
                add(vis[a[j]],-1);
            }
            add(j,1);
            vis[a[j]]=j;
        }
        next=ask[i].r+1;
        ans[ask[i].pos]=query(ask[i].r)-query(ask[i].l-1);
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
