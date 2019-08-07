#include<stdio.h>
int main()
{
    int n,o,d,sum=0;
    scanf("%d%d%d",&n,&o,&d);
    int i,temp=0,tt;
    for(i=0;i<n;i++)
    {
        scanf("%d",&tt);
        if(tt==1)
        {
            if(o==0)
            {
                if(d!=0)
                {

                    if(temp==0)
                    {
                        temp=1;d--;
                    }
                    else
                    {
                        temp--;
                    }
                }
                else if(d==0&&temp==1)
                {
                       temp=0;
                }
                else if(d==0&&temp==0)
                {
                    sum++;
                    continue;
                }
            }
            else
            {
                o--;
            }
        }
        else
        {
            if(d==0)
            {
                sum+=2;continue;
            }
                else
                    d--;

        }

    }



    printf("%d",sum);
    return 0;
}
