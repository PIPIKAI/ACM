#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#define inf 99999999
int a[1000][1000];
int d[1000];//d��ʾĳ�ض��߾���
int p[1000];//p��ʾ���ñ߾���
int i,j,k;
int m;//m�������
int n;//n�������
int main()
{
    scanf("%d%d",&n,&m);
    int min1;
    for(i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=z;
        a[y][x]=z;
    }

    memset(d,inf,sizeof(d));
    d[1]=0;
    for(i=1;i<=n;i++)
    {
        min1=inf;
        for(j=1;j<=n;j++)
            if(!p[j]&&d[j]<min1)
            {
                min1=d[j];
                k=j;
            }
        p[k]=j;
        for(j=1;j<=n;j++)
            if(a[k][j]!=0&&!p[j]&&d[j]>d[k]+a[k][j])
                d[j]=d[k]+a[k][j];
    }
    for(i=1;i<n;i++)
        printf("%d->",p[i]);
    printf("%d\n",p[n]);
    return 0;
}
