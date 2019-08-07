#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n;
const int maxn=32050;
int f[maxn]={0},ans[maxn]={0};
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
    while(x<maxn){
        f[x]+=val;
        x+=lowbit(x);
    }
}
int main()
{
    ///std::ios::sync_with_stdio(false);
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x+=1;
            ans[ query(x)]+=1;
            add(x,1);
        }
        for(int i=0;i<n;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
