#include<stdio.h>
typedef long long ll;
int f[1000005]={0};
int b[50]={0};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++)
    {
        char cc;
        scanf("%c",&cc);
        b[cc-'a']++;
        f[i]=b[cc-'a'];
    }
    for(int i=0;i<m;i++)
    {
        int q;
        scanf("%d",&q);
        printf("%d\n",f[q]);
    }
   return 0;
}

