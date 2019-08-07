#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 100
int prim[MAX];
int biao()
{
    memset(prim,1,sizeof(prim));
    prim[1]=0;
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(prim[i])
        {
           for(int j=2;i*j<=MAX;j++)
            prim[i*j]=0;
        }
    }
}
int main()
{
    biao();
    for(int i=1;i<MAX;i++)
        if(prim[i])
        cout<<i<<endl;

    return 0;
}
