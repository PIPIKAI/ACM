#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct
{
    int x,y;
}node;
bool cmp(node a,node b)
{
    if(a.x==b.x)
    return a.y<b.y;
    else
    return a.x<b.x;
}
int main()
{
    int n,ans=1;
    cin>>n;
    node f[n];
    for(int i=0;i<n;i++)
    {
        int ta,tb;
        cin>>ta>>tb;
        if(ta>tb)
            swap(ta,tb);
        f[i].x=ta;
        f[i].y=tb;
    }
    sort(f,f+n,cmp);
    int flag=0;
    node t;
    t.y=f[0].y;
    for(int i=1;i<n;i++)
        {
            if(f[i].x>=t.y)
            {
                t.x=t.y;
                flag=1;
                t.y=f[i].y;
                ans++;
            }
            if(t.y>f[i].y)
            {
                t.y=f[i].y;
            }

        }
cout<<ans<<endl;
        return 0;

}

/*
10
-94 -49
-90 48
-75 -15
-54 53
-45 75
0 94
2 97
20 89
58 96
66 103
*/
