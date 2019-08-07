#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
struct node{
    int x,y,t;
    bool operator < (node ta){
        return t<ta.t;
    }
};
node f[100005];
int vis[1002];
int find(int x)
{
    while(vis[x]!=x){
        x=vis[x];
    }
    return x;
}
void mer(int x,int y)
{
    int f1=find(x);
    int f2=find(y);
    if(f1<f2)
        vis[f2]=f1;
    if(f1>f2)
        vis[f1]=f2;
}
bool juge(){
    int t=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            t++;
        }
    }
    return t==1 ?  true : false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        vis[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>f[i].x>>f[i].y>>f[i].t;
    }
    if(m<n-1){
        return cout<<-1<<endl,0;
    }
    sort(f,f+m);
    int i;
    for(i=0;i<m;i++){
        mer(f[i].x,f[i].y);
        if(juge()){
            break;
        }
    }
    if(i>=m){
        cout<<-1<<endl;
    }
    else{
        cout<<f[i].t<<endl;
    }
    return 0;
}
