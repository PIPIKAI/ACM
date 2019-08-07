#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 5e4 + 7;
int n, m;
int a[maxn];
struct node {
    int s, w;
    bool operator < ( node x) const {
    return w>x.w;
    }
}f[maxn];
bool cmp(node a,node b)
{
    return a.s>b.s;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    priority_queue<node> q;
    for(int i = 0,t; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < m; i++) {
        cin>>f[i].s>>f[i].w;
    }
    sort(f,f+m,cmp);
    ll flag=0,ans=0;
    int j=0;
    for(int i=n-1;i>=0;i--){
       for(;j<m;){
            if(f[j].s>=a[i]){
                q.push(f[j]);
                j++;
            }
            else{
                break;
            }
       }
       if(q.empty()){
        flag=1;
        break;
       }
       else{
        ans+=q.top().w;
        q.pop();
       }
    }
    flag==0 ? cout<<ans<<endl : cout<<"No Solution"<<endl;
    //cout<<ans<<endl;
    return 0;
}
