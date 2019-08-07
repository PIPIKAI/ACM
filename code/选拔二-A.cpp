#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int x,y;
};
int jj(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
node qq(node a,node b)
{
    node t;
    t.x=(a.x+b.x)/2;
    t.y=(a.y+b.y)/2;
    return t;
}
double kk(node a,node b)
{
    double k=-(a.x-b.x)/(a.y-b.y);
    return k;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int n;
    int flag=1;
    node f[200],zhong;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i].x>>f[i].y;
    node a=qq(f[0],f[1]);
    double k1 = kk(f[0],f[1]);
    node b=qq(f[0],f[2]);
    double k2=kk(f[0],f[2]);
    zhong.x=(a.x*k1+b.x*k2+b.y-a.y)/(k1-k2);
    zhong.y=k1*(zhong.x-a.x)+a.y;
    int biao=jj(f[0],zhong);
    for(int i=1;i<n;i++)
    {
        if(biao!=jj(f[i],zhong))
        {
            flag=0;
            break;
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
   return 0;
}
