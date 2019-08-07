#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n;
int up[30],le[30],vis[30][30],ans[900];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int a[30]={1},b[30]={1};/// 在初始位置预先射一箭
int orderr(int x,int y){
    return y+n*x; /// 坐标对应关系
}
bool juge(){
    for(int i=0;i<n;i++){
        if(up[i]!=b[i] || le[i]!=a[i])
            return false;
    }
    return true;
}
void dfs(int x,int y,int step){
    if(x==n-1 && y== n-1&&juge()){
        for(int i=0;i<step;i++){
            cout<<ans[i];
            if(i!=step-1)
            cout<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<4;i++){
        int cx=dx[i]+x,cy=dy[i]+y;
         if(cx>=0 &&cy>=0 &&cx<n &&cy<n && !vis[cx][cy] && a[cx]+1<=le[cx] && b[cy]+1<=up[cy]){
            ans[step]=orderr(cx,cy);
            vis[cx][cy]=1;
            a[cx]++;b[cy]++;
            dfs(cx,cy,step+1);
            vis[cx][cy]=0;
            a[cx]--;b[cy]--;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>up[i];/// 上方的箭
    }
    for(int i=0;i<n;i++){
        cin>>le[i];/// 左边的箭
    }
    vis[0][0]=1;
    cout<<0<<" ";
    dfs(0,0,0);
    return 0;
}
