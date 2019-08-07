#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=4e4+7;
int f[maxn];
int a[maxn];
struct node
{
    int id,num;
};
int main()
{
    std::ios::sync_with_stdio(false);
    int ans=0;
    cin>>n;
    for(int t,i=0;i<n;i++){
        cin>>t;
        a[t]++;
    }
    int cnt=0;
    queue<node> q;
    for(int i=0;i<maxn;i++){
        if(a[i]>1){
             q.push(node{i,a[i]-1} );
        }
        else if(!q.empty()&&a[i]==0 ){
            node tp=q.front();
            if(tp.num==1){
                q.pop();
            }
            else{
                q.front().num--;
            }
            ans+=(i-tp.id);
        }
    }
    cout<<ans<<endl;
    return 0;
}
