#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int f[200];
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            for(int j=x;j<=y;j++)
                f[j]++;
        }
        int cnt=0;
        for(int i=1;i<=m;i++)
             if(f[i]==0)
            {
                cnt++;
            }
        cout<<cnt<<endl;
        if(cnt==0)
            continue;
        for(int i=1;i<=m;i++)
        {
            if(f[i]==0)
            {
                cout<<i<<" ";
            }

        }
        cout<<endl;
    }
    return 0;
}
