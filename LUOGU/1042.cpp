#include<bits/stdc++.h>
using namespace std;
int main()
{
    char x ;
    int f[10000][2],cnt=0;
    int a=0,b=0,c=0,d=0;
    while(cin>>x,x!='E')
    {
        if(x=='W')
            a++,c++;
        if(x=='L')
            b++,d++;
        if((a>=11&&a-b>=2)||(b>=11&&b-a>=2))
        {
            cout<<a<<":"<<b<<endl;
            a=0;b=0;
        }
        if((c>=21&&c-d>=2)||(d>=21&&d-c>=2))
        {
            f[cnt][0]=c,f[cnt++][1]=d;
            c=0,d=0;
        }
    }
    cout<<a<<":"<<b<<endl;
    f[cnt][0]=c,f[cnt++][1]=d;
    cout<<endl;
    for(int i=0;i<cnt;i++)
        cout<<f[i][0]<<":"<<f[i][1]<<endl;

    return 0;
}

