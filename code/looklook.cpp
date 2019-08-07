#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 100;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;
char maze[MAX_N][MAX_M + 1];
int N, M;
int sx, sy; //起点的位置
int gx, gy; //终点的位置

int d[MAX_N][MAX_M];//储存起点到某一点的距离
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; //表明每次x和y方向的位移

void bfs()
{
    queue<P> que;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            d[i][j] = INF;  //初始化所有点的距离为INF
    que.push(P(sx, sy));
    d[sx][sy] = 0;  //从起点出发将距离设为0，并放入队列首端

    while (que.size()) //题目保证有路到终点，所以不用担心死循环
    {
        P p = que.front(); que.pop();//弹出队首元素
        int i;
        for (i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];//移动后的坐标
            //判断可移动且没到过
            if (0 <= nx&&nx < N&& 0 <= ny&&ny < M&&maze[nx][ny] != '#'&&d[nx][ny] == INF)/*之前到过的话不用考虑，因为距离
            在队列中递增，肯定
            不会获得更好的解*/
            {
                que.push(P(nx, ny));    //可以移动则设定距离为之前加一，放入队列
                d[nx][ny] = d[p.first][p.second] + 1;
                if(nx==gx && ny==gy) break;

                        }
        }
        if(i!=4) break;
    }

}

int main()
{
    cin>>N>>M;
    for (int i = 0; i < N; i++)
        cin>>maze[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (maze[i][j] == 'S')
            {
                sx = i; sy = j;
            }
            if (maze[i][j] == 'E')
            {
                gx = i; gy = j;
            }
        }
    bfs();
    cout<<d[gx][gy]<<endl;

    return 0;
}
