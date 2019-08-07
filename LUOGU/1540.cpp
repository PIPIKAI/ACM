#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ,m,ans=0,i,j,t;
    int head=0,tail=0,f[200]={0};
    cin>>m>>n;
    for( i=0;i<n;i++)
    {
         t;cin>>t;
        for( j=0;j<tail;j++)
        {
            if(t==f[j]) break;
        }
        if(j==tail)
        {
            ans++;
            if(head==m)
                head=0;
            if(tail<m)
                f[tail++]=t;
            else
                f[head++]=t;
        }
    }
    cout<<ans<<endl;
    return 0;
}
