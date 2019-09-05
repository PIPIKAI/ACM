#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
#define mem(A,B) memset(A, B, sizeof(A))
const int inf = 0x3f3f3f3f;
const int maxn=2e3+7;
std::vector<int> f[maxn];
int du[maxn],dp[maxn][2];
int n,rt;
void dfs(int now){
	for(int j=0 ; j<f[now].size();j++){
		int i=f[now][j];
		dfs(i);
		dp[now][0]+=dp[i][1];
		dp[now][1]+=min(dp[i][1],dp[i][0]);
	}
}
int main(int argc, char * argv[]) 
{
    //freopen("C:/Users/Administrator/Desktop/CODEING/code/data.in","r",stdin);
    //freopen("C:/Users/Administrator/Desktop/CODEING/code/data.out","w",stdout);
    std::ios::sync_with_stdio(false);
    while(~scanf("%d",&n)){
    	mem(du,0);
    	for(int i=0;i<n;i++){
    		dp[i][1]=1;
    		dp[i][0]=0;
    		int tp,pt,a;
    		scanf("%d:(%d) ",&pt,&tp);
    		f[pt].clear();
    		while(tp--){
    			scanf("%d",&a);
    			f[pt].push_back(a);
    			du[a]++;
    		}
    	}
    	int rt;
    	for(int i=0;i<n;i++){
    		if(!du[i])
    			dfs(rt=i);
    	}
    	printf("%d\n",min(dp[rt][0],dp[rt][1]));
    }
    return 0;
}