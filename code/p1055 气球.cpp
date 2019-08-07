/*
作者:kaiss
题目:p1055 气球
*/
#include <stdio.h>
#include<string.h>
int main()
{

    int i,j,n,count=1,kind=1;
    scanf("%d",&n);

    char str[n][255],oo[100][10][255],t[255];
    for(i=0;i<n;i++)
        scanf("%s",str[i]);
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
        {
                if(strcmp(str[j],str[j+1])>0)
            {
                strcpy(t,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],t);
            }


        }
    for(i=1;i<n;i++)
        {count++;

           if(strcmp(str[i],str[i-1])!=0)
           {
               kind++;
               if()
               oo[count][]
           }


        }
        printf("%d\n",kind);


}
