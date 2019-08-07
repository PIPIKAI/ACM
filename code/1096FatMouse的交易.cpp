#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
struct node
{
    double x,y;
};
bool cmp(node a,node b)
{
    return  a.x/a.y> b.x/b.y;
}
int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        node f[20000];
        double ans=0;
        if(m==-1&&n==-1)
            break;
         for(int i=0;i<n;i++)
        {
            cin>>f[i].x>>f[i].y;
        }
        sort(f,f+n,cmp);
        int i=0;
        while(m>0&&i<n)
        {
            if(m-f[i].y>0)
            {
                m-=f[i].y;
                ans+=f[i].x;
            }
            else
            {
                ans=ans+((double)(m*1.0)/f[i].y)*f[i].x;
                m=0;
                break;
            }
            i++;
        }
        printf("%.3lf\n",ans);
    }

    return 0;
}
/**
10 4
1 1
1 1
1 1
1 1
*/
