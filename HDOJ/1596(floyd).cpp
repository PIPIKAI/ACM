#include<bits/stdc++.h>
using namespace std;
double f[1020][1020];
int n;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(f[i][j]<f[k][i]*f[k][j])
                    f[i][j]=f[k][i]*f[k][j];
            }
        }
    }
}
int main()
{
   while(cin>>n)
   {
       memset(f,0,sizeof f);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%lf",&f[i][j]);
            }
        int q;
        floyd();
        scanf("%d",&q);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(f[a][b]==0)
                    printf("What a pity!\n");
            else
                    printf("%.3lf\n",f[a][b]);
        }
    }
    return 0;
}

