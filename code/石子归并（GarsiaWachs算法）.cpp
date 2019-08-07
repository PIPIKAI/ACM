#include<bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF
int f[200],ans=0,t;
void combine(int k)
{
    int temp=f[k]+f[k-1];
    ans+=temp;
    for(int i=k;i<t-1;i++)
        f[i]=f[i+1];
    t--;
    int j=0;
    for( j=k-1;f[j-1]<temp;j--)
        f[j]=f[j-1];
    f[j]=temp;
    while(j >= 2 && f[j] >= f[j-2])
     {
        int d = t - j;
         combine(j-1);
        j = t - d;
     }
}
int main()
{
    int n;
    while(cin>>n)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            cin>>f[i];
        }
        f[0]=INF;
        f[n+1]=INF-1;
        t=3;
        for(int i=3;i<=n+1;i++)
        {
            f[t++]=f[i];
            while(f[i-3]<f[i-1])
                combine(i-2);
        }
        while(t>3)
            combine(t-1);
        cout<<ans<<endl;
    }

    return 0;
}
