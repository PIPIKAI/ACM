#include<bits/stdc++.h>
using namespace std;
int f[10050][4];
int main()
{
    int n,ans=0,flag=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f[i][0]>>f[i][1]>>f[i][2]>>f[i][3];
    }
    int x,y;
    cin>>x>>y;
    for(int i=n-1;i>=0;i--)
    {
        if(f[i][0]<=x&&f[i][1]<=y&&f[i][0]+f[i][2]>=x&&f[i][1]+f[i][3]>=y)
        {
            flag=1;cout<<i+1<<endl;break;
        }
    }
    if(0==flag)
        cout<<"-1"<<endl;
    return 0;
}
