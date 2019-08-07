#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
struct node{
    int a,b,c;
    node (){}
    node (int x,int y,int z){a=x,b=y,c=z;}
};
node f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=0;i<n;i++){
            cin>>f[i].a>>f[i].b>>f[i].c;
        }
    }
    return 0;
}
