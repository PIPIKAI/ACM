#include<stdio.h>
#include<string.h>
void jl(int x,int len);
struct le
{
    char s[25];
    int len;
    int v;
};
struct le c[22];
int n,maxl;

void jl(int x,int len)
{
    for(int i=1;i<=n;i++)
    {
        if(c[i].v<2)
            for(int j=0;j<c[x].len;j++)
            {
                    if(c[x].s[j]==c[i].s[0])
                {
                    int ia=1,flag=1;
                    for(int xa=j+1;xa<c[x].len&&ia<c[i].len;ia++,xa++)
                    {
                        if(c[x].s[xa]!=c[i].s[ia])
                        {
                            flag=0;
                            break;
                        }
                    }

                        if(flag)
                        {
                            c[i].v++;
                            jl(i,len+c[i].len-ia);
                            c[i].v--;
                        }

                }
            }

    }

    if(len>maxl)
        maxl=len;

}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c[i].s);
        c[i].len=strlen(c[i].s);
    }
    scanf("%s",c[0].s);
    c[0].len=strlen(c[0].s);

    jl(0,c[0].len);
    printf("%d",maxl);
    return 0;
}
