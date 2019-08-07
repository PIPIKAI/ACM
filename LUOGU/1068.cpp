#include<bits/stdc++.h>
using namespace std;
struct node{
int num,so;
}f[5001];
bool cmp(node a,node b)
{
    if(a.so==b.so)
        return a.num<b.num;
    return a.so>b.so;
}
int main()
{
    int n,m,sum=0,pe=0;
    cin>>n>>m;
    m*=1.5;
    for(int i=0;i<n;i++) cin>>f[i].num>>f[i].so;
    sort(f,f+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(i==m-1)
            sum=f[i].so;
        if(i>=m)
        {
            if(f[i].so>=sum)
                pe++;
        }
        else
            pe++;
    }
    cout<<sum<<" "<<pe<<endl;
    for(int i=0;i<pe;i++) cout<<f[i].num<<" "<<f[i].so<<endl;
    return 0;
}
