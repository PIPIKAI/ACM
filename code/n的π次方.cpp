#include<iostream>
#include<cstdio>
#include<math.h>
#define pi acos(-1.0)
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int x;
        scanf("%d%d",&n,&x);
        printf("%.*lf\n",x,pow(n,pi));
    }
}
