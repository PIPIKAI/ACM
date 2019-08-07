#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[10001];
void bigN(int n)
{
    f[0]=1;
    int wei=0;
    for(int i=1;i<=n;i++)
    {
        int b=0;
       for(int j=0;j<=wei;j++)
       {
           f[j]=i*f[j]+b;
           b=f[j]/10000;
           f[j]%=10000;
       }
       if(b>0)
       {
           wei++;
           f[wei]=b;
       }
    }
    for(int i=wei;i>=0;i--)
        if(i==wei)
        printf("%d",f[i]);
    else
        printf("%04d",f[i]);
}
int main()
{

    int n;
    while(cin>>n)
    {
    memset(f,0,sizeof(f));
       bigN(n);
       cout<<endl;
    }
    return 0;
}

