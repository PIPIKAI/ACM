#include<stdio.h>
#include<queue>
using namespace std;
int x,y,z;
typedef struct
{
    int a,b;
    int step;
}que;

int book[100][100];
que  c,c1,t;
int   bfs(int a,int b)
{
    int i,flag=-1;
    queue<que>q;
    c.a=a,c.b=b;
    c.step=0;
    q.push(c);
    while(!q.empty())
    {
        c1=q.front();
        q.pop();
        if(c1.a==z||c1.b==z)
        {
            printf("%d",c1.step);
            flag=1;
            break;
        }
        if(book[c1.a][c1.b]==1)
            continue;
        book[c1.a][c1.b]=1;
        for(i=1;i<=6;i++)
        {
            t.step=c1.step+1;
            if(i==1&&c1.a>0){t.a=0;t.b=c1.b;q.push(t);}// a
            if(i==2&&c1.b>0){t.b=0;t.a=c1.a;q.push(t);}
            if(i==3&&c1.a!=0){t.a=x;t.b=c1.b;q.push(t);}
            if(i==4&&c1.b!=0){t.b=y;t.a=c1.a;q.push(t);}
            if(i==5&&c1.a!=0&&(y-c1.b)!=0)//a to b
            {
                c1.a<=(y-c1.b)?t.a=0,t.b=c1.a+c1.b:t.a=c1.a-(y-c1.b),t.b=y;q.push(t);
            }
            if(i==6&&c1.b!=0&&(x-c1.a)!=0)
            {
                c1.b<=(x-c1.a)?t.b=0,t.a=c1.b+c1.a:t.b=c1.b-(x-c1.a),t.a=x;q.push(t);
            }
        }
    }

    return flag;
}
int main()
{
    scanf("%d%d%d",&x,&y,&z);
    if(bfs(0,0)==-1)
    {
        printf("impossible\n");
    }
    return 0;
}
