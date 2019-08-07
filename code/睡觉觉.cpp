#include<stdio.h>
char str[20];
int main()
{
    int h,m,s;
    scanf("%s",str);
    scanf("%2d:%2d:%2d",&h,&m,&s);
    int secen,day=0;
    scanf("%d",&secen);
    while(secen)
    {
        s++;
        if(s==60)
        {
            m++;
            s=0;
        }
        if(m==60)
        {
            h++;
            m=0;
        }
        if(h==24)
        {
            h=0;
            day++;
        }
        secen--;
    }
    printf("%d",day);
    return 0;
}
