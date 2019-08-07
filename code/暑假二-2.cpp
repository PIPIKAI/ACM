#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
#include<stdio.h>
#define MAX 20050
using namespace std;
int s[40050];
struct node{
    int a,b,c;
}f[100050];
bool cmp(node a,node b)
{
    return a.c>b.c;
}
int Find(int x)
{
    int r=x;
    while(s[r]!=r)
        r=s[r];
    int i=x,j;
    while(i!=r)
    {
        j=s[i];
        s[i]=r;
        i=j;
    }
    return r;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
    for(int i=1;i<=n*2;i++)
        s[i]=i;
    sort(f+1,f+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int x=Find(f[i].a);
        int y=Find(f[i].b);
        if(x==y)
        {
            return cout<<f[i].c<<endl,0;
        }
        s[y]=Find(f[i].a+n);
        s[x]=Find(f[i].b+n);
        /* for(int j=1;j<=n*2;j++)
        {
            cout<<s[j]<<" ";
            if(j==n)
                cout<<endl;
        }*/
    }
    cout<<"0"<<endl;
    return 0;
}
