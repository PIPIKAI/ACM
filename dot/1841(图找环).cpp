#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
const int maxn=100005;
vector <int > ans;
struct node
{
    int next,to;
};
node edge[maxn*2];
int head[maxn],tot=0,w[maxn],n;/// 每个点的度
void add(int a,int b)
{
    edge[tot].to=b;
    edge[tot].next=head[a];
    head[a]=tot++;
}
void topsort()
{
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(w[i]==1)
            q.push(i);
    }
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        for(int i=head[tp]; i!=-1 ;i=edge[i].next){
            int j=edge[i].to;
            w[j]--;
            if(w[j]==1){
                q.push(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
            if(w[i]==2)
            ans.push_back(i);
}
int main()
{
    std::ios::sync_with_stdio(false);
    mem(head,-1);
    cin>>n;
    for(int i=1,a,b;i<=n;i++){
        cin>>a>>b;
        add(a,b);
        add(b,a);
        w[a]++;w[b]++;
    }
    topsort();
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        i!=ans.size()-1 ? cout<<" ": cout<<endl;
    }
    return 0;
}
