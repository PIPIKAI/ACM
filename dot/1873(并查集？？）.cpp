#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=1005;
int n,m,q,tot=1;
int fa[maxn*maxn];
int find(int x){
    while(fa[x]!=x){
        x=fa[x];
    }
    return x;
}
void mer(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a < b){
        fa[b]=a;
    }
    if(b<a){
        fa[a]=b;
    }
}
void ini()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fa[tot]=tot++;
        }
    }
}
int ans(){
    int sum=0;
    for(int i=1;i<tot;i++){
        if(i==find(i)){
            sum++;
        }
    }
    return sum;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    ini();
    while(q--){
        int a,b;
        cin>>a>>b;
        mer(a,b);
    }
    cout<<ans()<<endl;
    return 0;
}
