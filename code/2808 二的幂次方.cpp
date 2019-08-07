#include<stdio.h>
typedef long long ll ;
ll n;
void dfs(ll n)
{
    if(n==0)
    {
        printf("0");
        return ;
    }
        if(n==1)
        {
              printf("2(0)");
              return ;
        }
        else if(n==2)
        {
            printf("2");
            return ;
        }
        else
        {
            ll t=n,i=0;
            while(t) t>>=1,i++;  //juge the 2 de cifang
            int flag=1; // juge the + hao nuo iput
            for(i-=1;i>=0;i--)
            {
                if((n>>i)&1) //cheke  thisnow  wei  is 1?
                {
                    if(flag==1)
                        flag=0;
                    else
                        printf("+");// 1!  ni dong de
                    if(i!=1)
                        {
                            printf("2(");
                            dfs(i);
                            printf(")");
                        }
                    else
                        printf("2");
                }
            }
        }



}
int main()
{

    scanf("%lld",&n);
    dfs(n);
    return 0;
}

