#include<bits/stdc++.h>
using namespace std;
int h[10020];
int f[3001];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
        {
            scanf("%d",f+i);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               int t=f[i]+f[j];
                h[t]++;
            }
        }
        int k=0;
        for(int i=10010;i>=0;i--)
        {
            while(h[i]>=1)
            {
                printf("%d",i);
                h[i]--;
                k++;
                if(k==m)
                {
                     printf("\n");break;
                }
                else
                    printf(" ");
            }
            if(k==m)
                {
                     break;
                }
        }
    }
    return 0;
}
