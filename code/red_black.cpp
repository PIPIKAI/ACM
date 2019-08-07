# include <stdio.h>
char mp[21][21];
int next[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}, k=0, n, m;
void dfs(int x, int y)
{
    ++k; //��·�����
    int i, mx, my;
    for(i=0; i<4; ++i)
    {
        mx = x + next[i][0];
        my = y + next[i][1];
        if(mx<0||my<0||mx>=n||my>=m)//�ж������������ĸ������Ƿ���
            continue;

        if(mp[mx][my]=='.')//������·��ʱ���ȶ�ס��Ȼ���ٰ����ݹ飬�ж����·���������ҡ�
        {
            mp[mx][my] = '#';
            dfs(mx, my);
        }
    }
}
int main()
{
    int i, j;
    while(scanf("%d%d",&m,&n),m+n!=0)
    {
        k=0;
    for(i=0; i<n; ++i)
        scanf("%s",mp[i]);
    for(i=0; i<n; ++i)
        for(j=0; j<m; ++j)
        {
            if(mp[i][j]=='@')//����ʼ��
            {
                dfs(i, j);
                break;
            }
        }
    printf("%d\n",k);
    }
    return 0;
}
