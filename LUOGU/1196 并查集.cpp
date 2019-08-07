#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int f[30005],nums[30005];///当前队伍的长度
int dis[30005];/// 到队伍最头的距离
int find(int x)
{
    if(f[x]==x) return f[x];
    int fn= find(f[x]);
    dis[x]+=dis[f[x]];
    return f[x]=fn;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<30005;i++){
        f[i]=i;
        nums[i]=1;
    }
    while(t--){
        char c;
        int x,y;
        cin>>c>>x>>y;
        int fx=find(x);
        int fy=find(y);
        if(c=='M'){
            dis[fx]+=nums[fy];
            nums[fy]+=nums[fx];
            nums[fx]=0;
            f[fx]=fy;
        }
        else{
            if(fx==fy){
                cout<<abs(dis[x]-dis[y])-1<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}
