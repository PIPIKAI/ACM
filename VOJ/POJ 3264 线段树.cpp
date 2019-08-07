#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=5e4+7;
ll a[maxn];
ll st1[maxn][20];
ll st2[maxn][20]={inf};
void RMQ1(){
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            if(i+(1<<j)-1<=n){
                st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1)) ][j-1]);
            }
        }
    }
}
void RMQ2(){
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            if(i+(1<<j)-1<=n){
                st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1)) ][j-1]);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        st1[i][0]=st2[i][0]=a[i];
    }
    RMQ1();
    RMQ2();
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        int k=log2(r-l+1);
        ll a=max( st1[l][k],st1[r-(1<<k)+1][k] );
        ll b=min( st2[l][k],st2[r-(1<<k)+1][k] );
        printf("%lld\n", a-b );
    }
    return 0;
}
