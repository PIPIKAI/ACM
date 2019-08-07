#include<stdio.h>
struct infor
{
    char num[255];
    char name[255];
    char birth[255];
    float a;
    float b;
    float c;
};
void input(struct infor q[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s%f%f%f",q[i].num,q[i].name,&q[i].birth,&q[i].a,&q[i].b,&q[i].c);
    }
    return ;
}
void output(struct infor q[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s %s %s %.1f\n",q[i].num,q[i].name,q[i].birth,(q[i].a+q[i].b+q[i].c)/3);
    }
    return ;
}
int main()
{
    int n,i;
    scanf("%d\n",&n);
    struct infor q[n];
    input(q,n);
    output(q,n);
    return 0;
}
