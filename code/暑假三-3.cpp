#include<bits/stdc++.h>
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
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    while(cin>>n)
    {
            long long sum=0,wait=0;
            for(int i=0;i<n;i++)
        {
            cin>>f[i].w>>f[i].t;
            if(f[i].t==0||f[i].w==0)
                i--,n--;
        }
        sort(f,f+n,cmp);
        for(int i=0;i<n;i++)
        {
            wait+=f[i].t;
            sum+=f[i].w*wait;
        }
        cout<<sum<<endl;
    }

    return 0;
}
