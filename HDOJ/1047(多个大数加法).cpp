#include<bits/stdc++.h>
using namespace std;
long long  f[100005];
void init(string s)
{
    reverse(s.begin(),s.end());
    for(int j=0;j<=100000&&j<s.length();j++)
    {
        int t=s[j]-'0';
       f[j]=f[j]+t;
    }
}
void add()
{
    int wei=0;
    int j;
    for( j=0;j<=100000;j++)
    {
        int t=f[j];
        f[j]=(wei+t)%10;
        wei=(wei+t)/10;
    }
    for(j=100000;j>=0;j--)
        if(f[j]!=0)
            break;
    for(;j>=0;j--)
        cout<<f[j];
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    if(n==0)
        cout<<"0"<<endl;
    while(n--)
    {
        memset(f,0,sizeof(f));
    string s;
    string a="0";
        while(cin>>s)
        {
            if(s==a) {add();break;}
            else
                init(s);
        }
        if(n>0)
            cout<<endl;
    }
    return 0;
}
