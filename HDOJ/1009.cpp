#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    double a,b,x;
}f[1200];
bool cmp(node a,node b)
{
    return a.x>b.x;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n;
   double m;
    while(cin>>m>>n,m!=-1&&n!=-1)
    {
        double h=0,ans=0;
        for(int i=0;i<n;i++) cin>>f[i].a>>f[i].b,f[i].x=f[i].a*1.0/f[i].b;
        sort(f,f+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(h+f[i].b>m)
            {
                ans+=f[i].a*1.0*(m-h)/f[i].b;
                break;
            }
            else
                h+=f[i].b,ans+=f[i].a;
        }
        printf("%.3lf\n",ans);
    }
   return 0;
}
