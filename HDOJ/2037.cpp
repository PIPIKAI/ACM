#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b;
}f[200];
bool cmp(node x,node y)
{
    return x.b<y.b;
}
int main()
{
    int n;
    while(cin>>n,n!=0)
    {
        int ans=1,l=0;
        for(int i=0;i<n;i++)
        {
            cin>>f[i].a>>f[i].b;
        }
        sort(f,f+n,cmp);
        l=f[0].b;
         for(int i=1;i<n;i++)
        {
            if(f[i].a>=l)
            {
                ans++;
                l=f[i].b;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
