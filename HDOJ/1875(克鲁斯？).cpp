#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int  t[1100][2];
bool oh=false;
struct node{
    int a,b;
    double w;
}f[505000];
int vis[505000];
double ans;
int n,m;
bool cmp(node a,node b)
{
    return a.w<b.w;
}
void ini()
{
    m=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double temp=sqrt((t[i][0]-t[j][0])*(t[i][0]-t[j][0])+(t[i][1]-t[j][1])*(t[i][1]-t[j][1]));
            if(temp>=10.000000&&temp<=1000.000001)
            {
                f[m].a=i;
                f[m].b=j;
                f[m].w=temp;
                m++;
            }
        }
    }
}
int fin(int x)
{
    int r=x,i=x,j;
    while(r!=vis[r])
        r=vis[r];
    while(i!=r)
    {
        j=vis[i];
        vis[x]=r;
        i=j;
    }
    return r;
}
int mer(int a,int b)
{
    a=fin(a);
    b=fin(b);
    if(a==b)
        return 0;
        if(a<b)
            vis[b]=a;
        if(a>b)
            vis[a]=b;
    return 1;
}
void kus()
{
    int ju=0,cnt=0;
    sort(f+1,f+m,cmp);
     ans=0;
     for(int i=1;i<=m;i++)
    {
        vis[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(mer(f[i].a,f[i].b))
        {
            ans+=f[i].w,cnt++;
        }
        if(cnt==n-1)
        {
            ju=1;break;
        }
    }
    if(ju==1)
    printf("%.1lf\n",ans*100);
    else
        printf("oh!\n");
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    while(cin>>T)
          {
              while(T--)
              {
                  cin>>n;
                  memset(f,0,sizeof(f));
                   for(int i=1;i<=n;i++)
                   {
                        cin>>t[i][0]>>t[i][1];
                   }
                ini();
                kus();
              }
          }
    return 0;
}


