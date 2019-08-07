#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
struct node
{
    int a,b,c;
}f[50050];
bool cmp(node a,node b)
{
    return a.c<b.c;

}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
        }
        sort(f,f+n,cmp);
        double aa=0,bb=0,cc,ans=0;
        for(int i=1;i<n;i++)
        {
            aa =fabs(f[i].a-f[i-1].a);
            bb =fabs(f[i].b-f[i-1].b);
            cc =fabs(f[i].c-f[i-1].c);
            ans+= sqrt(aa*aa+bb*bb+cc*cc);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
