#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1000001]={0},hh=500000;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	while(~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            {
                int t;
                scanf("%d",&t);
                f[t+hh]=1;
            }
            int j=0;
            for(int i=1000000;i>=0;i--)
            {

                if(f[i])
                {
                    printf("%d",i-hh);
                    j++;
                    if(j==m)
                    {
                         printf("\n");break;
                    }
                    else
                       printf(" ");
                }
            }
    }
   return 0;
}
