#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef pair <int ,int > P;
char ma[50][50];
bool v[50][50];
int dir[4][2]={1,0, 0,1, -1,0, 0,-1};
int ans,a,b,n,m;
void BFS()
{
    int i;
    queue <P> que;
    que.push(P(a,b));
    while(que.size())
    {
        P p=que.front();
        que.pop();
        for(i=0;i<4;i++){
            int nx=dir[i][0]+p.first;
            int ny=dir[i][1]+p.second;
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!v[nx][ny])
            {
                v[nx][ny]=true;
                que.push(P(nx,ny));
                ans++;
            }
        }
    }
}
void dis()
{

for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
        if(v[i][j])
        cout<<"0";
    else
        cout<<"1";
    cout<<endl;
}
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0&&m!=0))
    {
    ans=1;
    memset(v,false ,sizeof(v));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin>>ma[i][j];
                if(ma[i][j]=='@')
                {
                    a=i;b=j;
                }
                else if(ma[i][j]=='#')
                    v[i][j]=true;
            }
        }
        v[a][b]=true;
        //dis();
        BFS();
        cout<<ans<<endl;
    }
    return 0;
}
