#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[300],n,m;
void ini()
{
    for(int i=0;i<=n;i++)
        vis[i]=i;
}
struct node
{
    int x,y;
}f[5000];
int fin(int x)
{
    while(x!=vis[x])
        x=vis[x];
    return x;
}
int mer(int x,int y)
{
    x=fin(x);
    y=fin(y);
    if(x==y)
        return 1;
    if(x<y)
        vis[y]=x;
    if(x>y)
        vis[x]=y;
    return 0;
}
int juge()
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==i)
            s++;
    }
    if(s==1)
        return 1;
    else
        return 0;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	int flag=0,tt=0;
	for(int i=0;i<m;i++)
    {
        cin>>f[i].x>>f[i].y;
    }
    ini();
    for(int i=0;i<m;i++)
    {
        if(mer(f[i].x,f[i].y))
            flag++;
    }
    tt=juge();
    if(flag==1&&tt)
    {
        cout<<"FHTAGN!"<<endl;
    }
    else
    cout<<"NO"<<endl;
    return 0;
}
/*
6 7
6 3
6 4
5 1
2 5
1 4
5 4
3 5
*/
