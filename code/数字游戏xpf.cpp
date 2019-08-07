#include <stdio.h>
#include<string.h>
#include<algorithm> 
int main()
{
    int mm,t,k,n,i,j,count=0,last=0,sum=0;
    char str[255];

    scanf("%d\n%s",&mm,str);
    count=strlen(str);
    int f[count];
    for(i=0;i<count;i++)
    {
         f[i]=str[i]-'0';sum+=f[i];
    }
    qicksort(f,0,count-1);
    if(sum>=mm)
  {
    printf("0");
   	return 0;
  }
   for(i=0;i<count;i++)
   {
       if((9-f[i]+sum)>=mm)
     	{
         last++;
         break;
     	}
       else
       	{
         sum+=(9-f[i]);
         last++;
       	}
    }

 printf("%d",last);
    return 0;
}

