/*��N��ѧ��ȥʳ�ã��ɽ̹ٹ涨������2�˻�3�����һ�飬���ж����ֲ�ͬ����ķ�����*/
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
