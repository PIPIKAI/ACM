#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int w,n,f[50000];
    int sum,a,b;
    int i,j;
    scanf("%d%d",&w,&n);

    for(i=0;i<n;i++ )
        {
            scanf("%d",&f[i]);
        }
    sort(f,f+n);
    sum=n;
   for(i=0,j=n-1;i<j;)
   {
        if(f[i]+f[j]<=w)
        {
            i++;
            j--;
            sum--;

        }
        else if(f[i]+f[j]>w)
            j--;
   }
    printf("%d",sum);

        return 0;
}



