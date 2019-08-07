#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
using namespace std;
struct aa
{
    int x,y;
};
typedef struct aa ff;
bool cmp(struct aa a,struct aa b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,m;
        long long maxl=0,sum=1;
        scanf("%d%d",&n,&m);
        ff f[100002];
        for(int i=0;i<n;i++) scanf("%d%d",&f[i].x,&f[i].y);
        sort(f,f+n,cmp);
        queue <ff> q;
        ff temp=f[0];
        for(int i=1;i<n;i++)
        {
            if(temp.y<=f[i].x) sum++;

            maxl=max(maxl,sum);
            temp.y=min(f[i].y,temp.y);
        }
        cout<<maxl<<endl;
    }

    return 0;
}
