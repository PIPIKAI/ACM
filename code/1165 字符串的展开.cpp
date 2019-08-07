/*
作者:kaiss
test 1
1 2 1
123-34-567-9
题目:p1165 字符串的展开
*/
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
   int i,p1,p2,p3,k=0,g,m,tt,count;
   scanf("%d%d%d",&p1,&p2,&p3);
   char str[255],tou[2555];
   tou[0]=0;
   scanf("%s",str);

   for(i=0;i<strlen(str);i++)
   {
       if(str[i]=='-')
       {
                  if(1==isdigit(str[i-1])&&1==isdigit(str[i+1]))//digit
               {
                   if(str[i-1]>=str[i+1])//>=
                   {
                       tou[k]=str[i];k++;
                   }
                   else if(str[i-1]==(str[i+1]+1))//==+1
                   {
                      k++;
                   }
                   else if(str[i-1]<str[i+1])//<
                   {

                           if(p1==3)
                           {
                               g=k;count=g;
                               while(k<g+(str[i+1]-str[i-1]-1)*p2)
                               {
                                   m=p2;
                                   while(m>0)
                                   {
                                        tou[k]='*';m--;k++;
                                   }
                               }

                           }
                           else
                           {
                               if(p3==1)
                               {
                                   g=k;count=g;
                                   while(k<g+(str[i+1]-str[i-1]-1)*p2)
                                   {

                                       m=p2;tt=str[i-1]+count-g+1;
                                       while(m>0)
                                   {
                                         tou[k]=tt;k++;m--;
                                   }
                                   count++;
                                   }
                               }
                               else if(p3==2)
                                   {
                                       g=k;count=g;
                                       while(k<g+(str[i+1]-str[i-1]-1)*p2)
                                   {

                                       m=p2;tt=str[i+1]-count+g-1;
                                           while(m>0)
                                       {
                                             tou[k]=tt;k++;m--;
                                       }
                                   count++;
                                   }
                                    }
                           }
                   }
               }//qian hou isdigit
               else if((1==isdigit(str[i-1])&&0==isdigit(str[i+1]))||(0==isdigit(str[i-1])&&1==isdigit(str[i+1])))
               {
                   tou[k]=str[i];k++;
               }//qinahou is differnt
               else if(0==isdigit(str[i-1])&&0==isdigit(str[i+1]))
               {
                    if(str[i-1]>=str[i+1])//>=
                   {
                       tou[k]=str[i];k++;
                   }
                   else if(str[i-1]==(str[i+1]+1))//==+1
                   {
                      k++;
                   }
                   else if(str[i-1]<str[i+1])//<
                   {
                       if(p1==3)  //is ******
                           {
                               g=k;count=g;
                               while(k<g+(str[i+1]-str[i-1]-1)*p2)
                               {
                                   m=p2;
                                   while(m>0)
                                   {
                                        tou[k]='*';m--;k++;
                                   }
                               }

                           }
                           else if(p1==1)
                           {
                               if(p3==1)
                               {
                                   g=k;count=g;
                                   while(k<g+(str[i+1]-str[i-1]-1)*p2)
                                   {

                                       m=p2;tt=str[i-1]+count-g+1;
                                       while(m>0)
                                   {
                                         tou[k]=tt;k++;m--;
                                   }
                                   count++;
                                   }
                               }
                               else if(p3==2)
                                   {
                                       g=k;count=g;
                                       while(k<g+(str[i+1]-str[i-1]-1)*p2)
                                   {

                                       m=p2;tt=str[i+1]-count+g-1;
                                           while(m>0)
                                       {
                                             tou[k]=tt;k++;m--;
                                       }
                                   count++;
                                   }
                                   }
                           }//
                           else if(p1==2)
                           {
                               if(p3==1)
                               {
                                   g=k;count=g;
                                   while(k<g+(str[i+1]-str[i-1]-1)*p2)
                                   {

                                       m=p2;tt=str[i-1]+count-g+1-32;
                                       while(m>0)
                                   {
                                         tou[k]=tt;k++;m--;
                                   }
                                   count++;
                                   }
                               }
                               else if(p3==2)
                                   {
                                       g=k;count=g;
                                       while(k<g+(str[i+1]-str[i-1]-1)*p2)
                                   {

                                       m=p2;tt=str[i+1]-count+g-1-32;
                                           while(m>0)
                                       {
                                             tou[k]=tt;k++;m--;
                                       }
                                   count++;
                                   }
                                   }
                           }
                   }

                }//qian hou isalphn
       }
        else
       {
            tou[k]=str[i];k++;
       }
   }

  for(i=0;i<k;i++)
  {
      printf("%c",tou[i]);
  }
    return 0;
}
