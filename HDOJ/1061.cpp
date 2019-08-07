#include<bits/stdc++.h>
using namespace std;
struct node{
    int f[10];
    int jie;
}k[11];
void biao()
{
    for(int i=0;i<=9;i++)
    {
        k[i].jie=0;
        k[i].f[1]=i;
        int t=i;
        for(int j=2;j<=100;j++)
        {
            t=(t*i)%10;
            if(t==k[i].f[1])
            {
                 k[i].jie=j-1;
                 break;
            }
            else
                k[i].f[j]=t;
        }
    }
}
void dis()
{
    for(int i=0;i<=9;i++)
    {
        for(int j=1;j<=k[i].jie;j++)
            cout<<k[i].f[j]<<" ";
        cout<<endl;
    }

}
int main()
{
    memset(k,0,sizeof(k));
    biao();
    //dis();
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            int t=n%10;
            int s=n%(k[t].jie);
        if(s==0)
            s=k[t].jie;
        cout<<k[t].f[s]<<endl;
        }

    }

    return 0;
}
