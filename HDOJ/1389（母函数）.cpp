#include<bits/stdc++.h>
using namespace std;
int c1[20000],c2[20000];
int main()
{
    int n;
    while(cin>>n,n)
    {
        for(int i=0;i<=n;i++)
        {
            c1[i]=1;
            c2[i]=0;
        }
        for(int i=2;i*i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;j+k<=n;k=k+i*i)
                {
                    c2[k+j]+=c1[j];
                }
            }
            for(int i=0;i<=n;i++)
            {
                c1[i]=c2[i];
                c2[i]=0;
            }
        }
        cout<<c1[n]<<endl;
    }

    return 0;
}
