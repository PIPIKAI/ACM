/*
作者:kaiss
题目:p1015 计算器的改良  6a-5+1=2-2a  a-5+1=2-2a
*/
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
   char str[255];
   gets(str);
   int kg=0,l=0,i,r=0,len;
   len=strlen(str);
   for(i=0;i<len;i++)
   {
       if(str[i]=='=')
       {
           kg=1;
           continue;
       }
       if(isalpha(str[i+1])==1&&isdigit(str[i])==1&&i==0)
       {
           if(kg==0)
            l+=str[i]-'0';
           else
            l-=str[i]-'0';
       }
       if(isalpha(str[i])==1&&i==0)
          {
              l+=1;
          }
          if(str[i]=='+')
          {
              if(isalpha(str[i+2])==0&&isdigit(str[i+2])==0)
                {

                }
          }
            if(str[i]=='-')
            {

            }
   }
   printf("%d",r/l);
    return 0;
}
