#include<iostream>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 110;
int graph[MAXN][MAXN];
int color[MAXN];
int n,m,num_col;

bool Judge(int x,int col)//�жϵ�ǰ����£�������ܱ�����col�����ɫ
{
    for(int i = 1;i <= n;i ++)
    {
        if(graph[i][x] && color[i] != 0 && color[i] == col )
            return false;
    }
    return true;
}
void Init()
{
    scanf("%d%d",&m,&n);
    int a,b;
    scanf("%d",&num_col);
    memset(graph,0,sizeof(graph));//��ͼ
    memset(color,0,sizeof(color));//ÿ�������ɫ
    for(int j =0 ;j < n;j ++)
    {
        scanf("%d%d",&a,&b);
        graph[a][b] = graph[b][a] = 1;
    }
}
void Solve(int pos)
{
    if(pos == n)
    {
        for(int i =1 ;i <= m;i ++)
            printf("%d%c",color[i],i==m?'\n':' ');
        return ;
    }
    for(int i = 1;i <= num_col;i ++)
    {
        if(Judge(pos,i))
        {
            color[pos] = i;
            Solve(pos+1);
            color[pos] = 0;
        }
    }
}
int main()
{
    Init();
    Solve(1);
}
