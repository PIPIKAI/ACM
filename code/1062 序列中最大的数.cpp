#include<iostream>
#include<cstring>
using namespace std;
int f[100005],k[100005];
void init()
{
    f[0]=0;
    f[1]=k[1]=1;
    for(int i=2;i<=100005;i++)
    {
        if(i&1)
        f[i]=f[(i-1)/2]+f[(i-1)/2+1];
        else
            f[i]=f[i/2];
       k[i]=max(k[i-1],f[i]);
    }
    return ;
}
int main()
{
    int n;
    init();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cout<<k[x]<<endl;
    }
    return 0;
}
