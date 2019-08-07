#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
int n,m;
priority_queue<int> maxd;///大的优先
priority_queue<int , vector<int >,greater<int> > mind;///小的优先
int a[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    int r=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1,t;i<=m;i++){
        cin>>t;
        for(int j=r;j<=t;j++){
            maxd.push(a[j]);
            if(maxd.size()==i){
                maxd.push(mind.top()),mind.pop();
            }
        }
        r=t+1;
            cout<<mind.top()<<endl;
            mind.push(maxd.top()),maxd.pop();
    }
    return 0;
}
