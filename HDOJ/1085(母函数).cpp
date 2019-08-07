#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int c1[9005],c2[9005];
int main()
{
    while(cin>>x>>y>>z,x||y||z)
    {
        int maxn=1*x+2*y+5*z;
        for(int i=0;i<=maxn;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        for(int i=0;i<=x*1;i++)
        {
            c1[i]=1;
        }
        for(int i=0;i<=x*1;i++)
        {
            for(int j=0;j<=y*2;j+=2)
                c2[j+i]+=c1[i];
        }
        for(int i=0;i<=y*2+x*1;i++)
        {
            c1[i]=c2[i];
            c2[i]=0;
        }
        for(int i=0;i<=y*2+1*x;i++)
        {
            for(int j=0;j<=z*5;j+=5)
                c2[i+j]+=c1[i];
        }
        for(int i=0;i<=z*5+y*2+x*1;i++)
        {
            c1[i]=c2[i];
            c2[i]=0;
        }
        int i;
        for( i=0;i<=maxn;i++)
        {
            if(c1[i]==0)
            {
                cout<<i<<endl;
                break;
            }
        }
        if(i==maxn+1)
            cout<<maxn+1<<endl;
    }
    return 0;
}
