#include<bits/stdc++.h>
using namespace std;
int n1,n2,n5;
int f[9005];
int main()
{
    while(cin>>n1>>n2>>n5,n1||n2||n5)
    {
        memset(f,0,sizeof(f));
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                for(int k=0;k<=n5;k++)
                {
                    int t=1*i+2*j+5*k;
                    f[t]=1;
                }
            }
        }
        for(int i=1;i<=9000;i++)
        {
            if(f[i]==0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
