/*有N个学生去食堂，可教官规定：必须2人或3人组成一组，求有多少种不同分组的方法。*/
#include<stdio.h>
long long  N;
long long  f[155];
int main()
{
    int i;
    scanf("%d",&N);
    f[1]=0,f[2]=f[3]=1;
    for(i=4;i<=N;i++)
        f[i]=f[i-2]+f[i-3];
    printf("%lld",f[N]);
    return 0;
}
