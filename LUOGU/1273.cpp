#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(A,B) memset(A, B, sizeof(A))
const int inf = 0x3f3f3f3f;
const int maxn=3e3+7;
std::vector<pair<int,int>> f[maxn];
int dp[maxn][maxn],money[maxn];// dp[i][j] 表示i节点为根的子树中，满足j个客户的最大收益
int n,m;
int dfs(int now){
    dp[now][0]=0;
    if(now > n-m){
        dp[now][1]=money[now];
        return 1;
    }
    int sum=0,tp;
    for(auto i:f[now]){
        int next=i.first;
        int w=i.second;
        tp=dfs(next);
        sum+=tp;
        for(int j=sum;j>0;j--){
            for(int k=1;k<=tp;k++){
                if(j-k >=0)
                dp[now][j]=max(dp[now][j],dp[next][k]+dp[now][j-k]-w);
            }
        }
    }
    return sum;
}
int main(int argc, char * argv[]) 
{
    //freopen("C:/Users/Administrator/Desktop/CODEING/code/data.in","r",stdin);
    //freopen("C:/Users/Administrator/Desktop/CODEING/code/data.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    mem(dp,~0x3f);
    for(int i=1,k;i<=n-m;i++){
        cin>>k;
        for(int j=0,a,w;j<k;j++){
            cin>>a>>w;
            f[i].push_back(make_pair(a,w));
        }
    }
    for(int i=n-m+1;i<=n;i++){
        cin>>money[i];
    }
    dfs(1);
    for(int i=m;i>=1;i--){
        if(dp[1][i]>=0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}