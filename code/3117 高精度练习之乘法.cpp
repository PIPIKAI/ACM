#include<iostream>
#include<cstring>
using namespace std;
string aa,bb;
int a[600],b[600],c[600*600];
int main()
{
    int i,j,x,y;
    cin>>aa>>bb;
    x=aa.length();
    y=bb.length();
    for(i=x-1,j=0;i>=0;i--,j++) a[j]=aa[i]-'0';
    for(i=y-1,j=0;i>=0;j++,i--) b[j]=bb[i]-'0';

    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            c[i+j]+=a[i]*b[j];
    for(i=0;i<=600*600;i++)
    {
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while(c[i]==0)i--;
    if(i<=0)
        cout<<"0";
    for(;i>=0;i--)
        cout<<c[i];
    return 0;
}

