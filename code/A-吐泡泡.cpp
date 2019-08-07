#include<stdio.h>
#include<string.h>
int main()
{
    char str[106];
    while(~scanf("%s",str))
    {
        int i,j,len=strlen(str);
        for(i=0;i<len;)
            {
                if(str[i]=='O'&&str[i+1]=='O')
                {
                    for(int p=i;p<len-1;p++)
                       str[p]=str[p+2];//前移两位 
                       
                       i=0;
                       len-=2;
                }
                else if((str[i]=='o'&&str[i+1]=='o'))
                {
                	str[i]='O';
                	for(int p=i+1;p<len;p++)
                       str[p]=str[p+1];//前移一位 
                       
                       i=0;
                       len--;
				}
				else
				{
				i++;
				}
				
            }
            for(i=0;i<len;i++)
        printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
