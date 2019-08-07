#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
ll n,m,cc,ans=0;
int f[600][600]={0};
/**
1 只能站在 11 或 22 的肩上。
2 只能站在 12 或 21 的肩上。

1
11
222
1212
*/

void dfs(int a,int b,int x,int y){
    if(a<0 || b<0){
        return ;
    }
    if(y==x){
        dfs(a,b,x+1,1);
    }
    if(a==0&&b==0&&x==cc+1){
        ans++;
        return;
    }
    int l=f[x][y-1],up=f[x-1][y-1];
    if(l==0){
        f[x][y]=1;
        dfs(a-1,b,x,y+1);
        f[x][y]=2;
        dfs(a,b-1,x,y+1);
    }
    else if(l==1){
        if(up==1){
            f[x][y]=1;
            dfs(a-1,b,x,y+1);
        }
        else if(up==2){
            f[x][y]=2;
            dfs(a,b-1,x,y+1);
        }
    }
    else if(l==2){
        if(up==1){
            f[x][y]=2;
            dfs(a,b-1,x,y+1);
        }
        else if(up==2){
            f[x][y]=1;
            dfs(a-1,b,x,y+1);
        }
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=500;i++){
        if( 2*(n+m) == (1+i)*i ){
            cc=i;
            break;
        }
    }
    dfs(n,m,1,1);
    cout<<ans<<endl;
    return 0;
}
