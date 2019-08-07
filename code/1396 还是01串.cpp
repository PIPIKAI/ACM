#include<bits/stdc++.h>
using namespace std;
int f[1000005][2];
typedef long long ll;
int main ()
{
    memset(f,0,sizeof(f));
    int flag=0;
    string  s;
    ll a=0,b=0;
    cin>>s;
    ll sum=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            a++;
        else
            b++;
        f[i+1][0]=a,f[i+1][1]=b;
    }
    /*for(int i=1;i<=s.length();i++)
        cout<<f[i][0]<<"  "<<f[i][1]<<endl;*/
     for(int i=1;i<=s.length();i++)
     {
         if(f[i][0]==(b-f[i][1]))
            return cout<<i<<endl,0;
     }
    if(b==0)
    cout<<"0"<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
