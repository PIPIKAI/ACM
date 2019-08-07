#include<stdio.h>
#include<math.h>
int add(int x,int y,int z)
{
    int sum=0;
    while(z>0)
    {
        sum+=x;
        x+=y;
        z--;
    }
    return sum;
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    printf("%d",add(a,b,c));

}


