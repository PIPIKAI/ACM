#include<stdio.h>
#include<string.h>
int n,a,b,minl=99999;
int f[100];
int book[100];
int aa[100];
int juge()
{
    for(int i=1;i<=n;i++)
        if(f[i]>=0)
        return 0;
    return 1;
}
void dfs(int step,int ans)
{




    for(int i=2;i<=n-1;i++)
    {
        if(juge())
        {
            minl=minl<ans?minl:ans;
            return ;
        }
        if(book[i]==0)
           {
               if(i!=n-1)
            {
                int c=0;
                        while(f[i]>=0)
                    {
                        f[i]-=b;f[i+1]-=a;f[i+2]-=b;
                        c++;
                        ans++;
                    }
                    book[i]=1;
                    dfs(step+1,ans);
                    book[i]=0;
                    f[i+1]+=a*c;
                    f[i+2]+=b*c;
                    f[i]+=b*c;
                ans-=c;
                c=0;
                while(f[i]>=0)
                    {
                        f[i]-=a;f[i+1]-=b;f[i-1]-=b;
                        c++;
                        ans++;
                    }
                    book[i]=1;
                    dfs(step+1,ans);
                    book[i]=0;
                    f[i]+=a*c;
                    f[i+1]+=b*c;
                    f[i-1]+=b*c;

            }
            else
            {
                    int c=0;
                        while(f[i]>=0)
                    {
                        f[i-1]-=a;f[i-2]-=b;f[i]-=b;
                        c++;
                        ans++;
                    }
                    book[i]=1;
                    dfs(step+1,ans);
                    book[i]=0;
                    f[i-1]+=a*c;
                    f[i-2]+=b*c;
                    f[i]+=b*c;

                ans-=c;
                c=0;
                while(f[i]>=0)
                    {
                        f[i]-=a;f[i+1]-=b;f[i-1]-=b;
                        c++;
                        ans++;
                    }
                    book[i]=1;
                    dfs(step+1,ans);
                    book[i]=0;
                    f[i]+=a*c;
                    f[i+1]+=b*c;
                    f[i-1]+=b*c;
            }
           }

    }

}
int main()
{
    int f[100];
    memset(book,0,sizeof(book));
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    int add=0;
    while(f[1]>=0)
    {
        f[1]-=b;
        f[2]-=a;
        f[3]-=b;
        add++;
    }

    while(f[n]>=0)
    {
        f[n]-=b;
        f[n-1]-=a;
        f[n-2]-=b;
        add++;
    }
    if(n==3&&f[2]<0)
    {
        printf("%d\n",add);
        return 0;
    }

    dfs(0,0);
    printf("%d\n",minl+add);
    return 0;
}
