#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
struct node{
    int x,y;
} f[100050];
bool cmp(node a,node b){
    return a.y<b.y;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i].x>>f[i].y;
    }
    sort(f,f+n,cmp);
    int ans=1,k=f[0].y;
    for(int i =1;i<n;i++){
        if(f[i].x>=k){
            k=f[i].y;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
