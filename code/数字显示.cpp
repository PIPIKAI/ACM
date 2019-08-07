#include<stdio.h>
char iput[5][40];
struct app
{
    char a[15];
};
/*char digt[][15]={
{"0000 00 00 0000"},
{" 1 11  1  1 111"},
{"222  22222  222"},
{"333  3333  3333"},
{"4 44 4444  4  4"},
};
*/
int main()
{
struct app digt[10];
digt[0].a="0000 00 00 0000";


    input_it();
    return 0;
}

void input_it(void)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<0;j++)
    {
        putchar (iput[i][j]);
    }
    putchar('\n');
    }
     return ;
}
