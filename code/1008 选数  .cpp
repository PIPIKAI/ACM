#include<stdio.h>
#include<math.h>
typedef long long ll;
ll f[30],sum=0,add=0;
int k,n,book[30]={0};
int isapa(ll n)
{
    int i;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

void dfs(int pos,int step)
{
    if(step>k)
    {
        if(1==isapa(add))
            sum++;
            return ;
    }
    if(pos>n)
        return ;
    dfs(pos+1,step);
    add+=f[pos];
    dfs(pos+1,step+1);
    add-=f[pos];

}

int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%lld",&f[i]);
    dfs(1,1);
    printf("%lld",sum);
return 0;
}
