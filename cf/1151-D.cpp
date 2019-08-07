#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
int n,k;
struct node
{
    ll l,r;
     friend bool operator< (node n1, node n2)
    {
        return  n1.l+n2.r < n1.r+n2.l ;;
    }
    node(){}
    node (ll a,ll b){l=a,r=b;}
};
priority_queue<node> q;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    ll l,r;
    for(ll i=1;i<=n;i++){
        cin>>l>>r;
        q.push(node(l,r));
    }
    ll sum=0,i=0;
    while(!q.empty()){
        i++;
        node tp=q.top();
        sum+=tp.l*(i-1)+tp.r*(n-i);
        q.pop();
    }
    cout<<sum<<endl;
    return 0;
}
