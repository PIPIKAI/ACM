#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int x,y;
}F;
bool cmp(F a ,F b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int n,ans=1;
    F f[10005];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i].x>>f[i].y;
    sort(f,f+n,cmp);
    priority_queue<int,vector<int>, greater<int > > q;
    q.push(f[0].y);
    int i;
    for(i=1;i<n;i++)
    {
           if(f[i].x>=q.top())
            q.pop();
           else
            ans++;
           q.push(f[i].y);
    }
    cout<<ans<<endl;
    return 0;
}
