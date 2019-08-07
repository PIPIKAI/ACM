#include<stdio.h>
int main()
{
    int l,n,sum=0,i,j=0,flag,k,bflag,count=0,mark[100]={-9},win=0;
    scanf("%d%d",&l,&n);
    int f[n][2],t[n][2];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&f[i][0],&f[i][1]);
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
    {
        flag=0;
        if(i==j)
            continue;

       for(k=0;k<=count;k++)
       {
           if(mark[k]==j)
            flag=1;
       }
       if(flag==1)
        continue;
        else
        {
            if(f[i][0]>=f[j][0]&&f[i][1]<=f[j][1])
            {
                f[i][0]=f[j][0];f[i][1]=f[j][1];
                mark[count++]=j;
            }
            else if(f[i][0]<=f[j][0]&&f[i][1]>=f[j][1])
                {
                mark[count++]=j;
                }
            else if(f[i][1]>f[j][1]&&f[i][0]<=f[j][1])
            {
                f[i][0]=f[j][0];
                mark[count++]=j;
            }
            else if(f[j][1]>f[i][1]&&f[j][0]<=f[i][1])
            {
                f[i][1]=f[j][1];
                mark[count++]=j;
            }

        }

    }
    }

    // add
        for(i=0;i<n;i++)
        {
            for(flag=0,k=0;k<count;k++)
       {
           if(mark[k]==i)
            flag=1;
       }
       if(flag==1)
       {
           continue;
       }
       else
        sum=sum+f[i][1]-f[i][0]+1;
        }
    printf("%d",l-sum+1);
    return 0;
}

