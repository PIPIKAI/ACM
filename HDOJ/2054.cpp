#include<bits/stdc++.h>
using namespace std;
void bb( string &a)
{
    int len=a.length()-1;
    if(a.find('.')!=string::npos)
    {
        for(int i=len;a[i]=='0';i--)
            len--;
        a=a.substr(0,len);
    }
    if(a[len-1]=='.')
        a=a.substr(0,len-1);
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        bb(a);
        bb(b);
   if(a==b)
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;
    }

    return 0;
}


