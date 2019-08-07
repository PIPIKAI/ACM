#include<stdio.h>
#include<stdlib.h>
typedef struct Data
{
    int left;
    int right;
}DataType;
DataType f[20];
void inti()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&f[i].left,&f[i].right);
}
void pre_display(int i)
{
    if(i==0)
        return ;
    printf("%d ",i);
    pre_display(f[i].left);
    pre_display(f[i].right);
}
void mid_display(int i)
{
    if(i==0)
        return ;
    mid_display(f[i].left);
    printf("%d ",i);
    mid_display(f[i].right);
}
void bac_display(int i)
{
    if(i==0)
        return ;
    bac_display(f[i].left);
    bac_display(f[i].right);
    printf("%d ",i);
}
int main()
{
    inti();
    pre_display(1);
    printf("\n");
    mid_display(1);
    printf("\n");
    bac_display(1);
   return 0;
}
