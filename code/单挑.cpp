#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    int a=1,b=2,c=3;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t==c)
        {
            printf("NO\n");
            return 0;
        }
        if(t==a)
            swap(b,c);
        else if(t==b)
            swap(a,c);
    }
    printf("YES\n");
    return 0;
}
