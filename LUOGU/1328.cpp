#include<bits/stdc++.h>
using namespace std;
int f[5][5]={
    0,0,1,1,0,
    1,0,0,1,0,
    0,1,0,0,1,
    0,0,1,0,1,
    1,1,0,0,0,
};
int main()
{
    int n ,a,b,as=0,bs=0;
    cin>>n>>a>>b;
    int x[500],y[500];
    for(int i=0;i<a;i++)  cin>>x[i];
    for(int i=0;i<b;i++)  cin>>y[i];
    for(int i=0;i<n;i++)
    {
        as+=f[x[i%a]][y[i%b]];
        bs+=f[y[i%b]][x[i%a]];
    }
    cout<<as<<" "<<bs<<endl;
    return 0;
}
