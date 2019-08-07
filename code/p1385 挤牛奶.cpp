/*
作者:kaiss
题目:p1385 挤牛奶
*/

#include <stdio.h>
int main()
{
    int a, b,con[100]={0},nob[100],p=0,q=0; //定义两个变量名
    scanf("%d", &a);
    int f[a][2],max_con,max_nob;
    int i;
    for(i=0;i<a;i++)
        scanf("%d%d",&f[i][0],&f[i][1]);
        if(a==1)
        {
            printf("%d %d",f[0][0],0);
            return 0;
        }
    for(i=1;i<a;i++)
    {
        if(f[i-1][1]>=f[i][0])
        {

            if(con[p]==0)
                con[p]=con[p]+f[i][1]-f[i-1][0];
                else
                con[p]+=f[i][1]-f[i-1][1];

        }
        else if(f[i-1][1]<f[i][0])
        {
            if(con[p]==0)
            {
                con[p]=con[p]+f[i][1]-f[i][0];
            }
            p++;
            nob[q]=f[i][0]-f[i-1][1];
            q++;
        }
    }
    max_con=0;
    max_nob=0;
    for(i=0;i<p;i++)
    {
        if(con[i]>max_con)
            max_con=con[i];
    }
    for(i=0;i<q;i++)
    {
        if(nob[i]>max_nob)
            max_nob=nob[i];
    }
    printf("%d %d",max_con,max_nob);
    return 0;
}

