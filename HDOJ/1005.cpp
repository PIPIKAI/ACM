#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int f[100]={0};
int main()
{
    int a,b,n;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF&&(a!=0&&b!=0&&n!=0))
    {
        f[0]=f[1]=1;
        int cc=3,jie;
        for(int i=2;i<49;i++)
        {
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        }
        /*while(cc<=n)
        {
            f[cc]=(a*f[cc-1]+b*f[cc-2])%7;
            //cout<<f[cc]<<endl;
            if(f[cc-1]==1&&f[cc-2]==1&&cc!=3)
            {
                jie=cc-3;
                //cout<<" jie= "<<jie<<endl;
                f[0]=f[cc];
                break;
            }
            cc++;
        }*/
        cout<<f[(n-1)%49]<<endl;
    }
    return 0;
}
