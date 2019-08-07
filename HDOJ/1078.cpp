#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 105
using namespace std;
int dp[MAX][MAX];
int n,k;
int map[MAX][MAX];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void dis()
{
    for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                cout<<dp[i][j]<<" ";
                }
				cout<<endl;
            }
            system("pause");
}
int dfs(int x, int y)
	{

		if(dp[x][y] != -1)
			return dp[x][y];

		int res = map[x][y];//dp[x][y]最少为map[x][y] 终点时候 就是此值
		for(int i = 0; i < 4; ++i){
			for(int j = 1; j <= k; ++j){
				int nx = x + j*dir[i][0];
				int ny = y + j*dir[i][1];
				if(nx>=0 && nx<n && ny>=0 &&ny<n && map[nx][ny] > map[x][y]){
					res = max(res,dfs(nx,ny)+map[x][y]);//就是状态转移方程的 搜索形式
					//dis();
				}
			}
		}
		return dp[x][y] = res;
	}

int main()
	{
		std::ios::sync_with_stdio(false);//加快读取速度
		while(cin >> n >> k){
			if(n == -1 && k == -1)
				break;
			memset(dp,-1,sizeof(dp));
			memset(map,0,sizeof(map));

			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					cin >> map[i][j];
				}
			}
			int ans = dfs(0,0);

		}

		return 0;
	}
