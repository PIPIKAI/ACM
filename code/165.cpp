#include<stdio.h>
#include<math.h>
int main()
{
    float a,b;
    char c;
    scanf("%f%c%f",&a,&c,&b);
    if(c=='+')
    {
        printf("%.2f",a+b);
    }
    else if(c=='-')
    {
        printf("%.2f",a-b);
    }
    else if(c=='*')
    {
        printf("%.2f",a*b);
    }
    else if(c=='/')
        printf("%.2f",a/b);
    else if(c=='^')
        printf("%.2f",pow(a,b));
        else
            printf("Error");
    return 0;
}
