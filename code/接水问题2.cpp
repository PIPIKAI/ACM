#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct aa
{
    int w,t;
}f[100002];
bool cmp(struct aa a,struct aa b)
{
    return a.w*b.t>b.w*a.t;
}
int main()
{
    int n;
    long long sum=0,wait=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&f[i].w,&f[i].t);
        if(f[i].t==0||f[i].w==0)
            i--,n--;
    }
    sort(f,f+n,cmp);
    for(int i=0;i<n;i++)
    {
        wait+=f[i].t;sum+=f[i].w*wait;
    }
    cout<<sum<<endl;
    return 0;
}
