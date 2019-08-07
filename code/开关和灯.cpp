#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int f[3000][3000];
int sum[3000]={0};
int main()
{
    int n,m,isno=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int t;
             scanf("%1d",&t);
            f[i][j]=t;
            if(t)
                sum[j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        for(int k=1;k<=m;k++)
        {
            if(f[i][k]==sum[k])
            {
                flag=0;break;
            }
        }
        if(flag)
            return cout<<"YES"<<endl,0;
    }
        cout<<"NO"<<endl;

        /* for(int j=1;j<=m;j++)
         cout<<ju[j];
         cout<<endl;*/
    return 0;
}

