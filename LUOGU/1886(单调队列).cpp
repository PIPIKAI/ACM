#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
const int maxn=1000050;
int f[maxn];
int q[maxn][2];
int ans[maxn][2];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    int tail=1,head=1;
    q[tail++][0]=f[1];
    for(int i=1;i<=n+1;i++){
        if(i- q[head][1] > m){
            head++;
        }
        if(i>m)
        cout<<q[head][0]<<" ";
        while(head < tail && q[tail-1][0] > f[i]){
            tail--;
        }
        q[tail][0]=f[i];
        q[tail][1]=i;
        tail++;
    }
    cout<<endl;
    tail=1,head=1;
    for(int i=1;i<=n+1;i++){
        if(i- q[head][1] > m){
            head++;
        }
        if(i>m)
        cout<<q[head][0]<<" ";
        while(head < tail && q[tail-1][0] < f[i]){
            tail--;
        }
        q[tail][0]=f[i];
        q[tail][1]=i;
        tail++;
    }
    return 0;
}
