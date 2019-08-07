#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int   f[10005];
int  h[12]={0};
int main()
{
    int n,k,avr=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%1d",f+i);
        h[f[i]]++;
        avr+=f[i];
    }
    avr/=n;
    int t1,t2=99999;
    for(int i=1;i<=9;i++)
    {
        int b=abs(avr-h[i]);
        if(t2>b)
        {
            t1=i;
            t2=b;
        }
    }
    cout<<t1<<endl;
    return 0;
}
