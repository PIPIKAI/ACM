#include<bits/stdc++.h>
using namespace std;
string bb(int n)
{
    string s;
    while(n!=0)
    {
        int t=n%10;
        char c='0'+t;
        n/=10;
        s=c+s;
    }
    return s;
}
int main()
{
    string s="1";
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int b;
        string c,tt=bb(i);
        cin>>c>>b;
        int j=s.find(c);
        if(b==0)
            s.insert( j , tt );
        else
            s.insert(j+1, tt );
        cout<<s<<endl;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        char c;
        cin>>c;
        int j=s.find(c);
        if(j!=-1)
            s.erase(j,j+0);
    }
    for(int i=0;i<s.length();i++){
        cout<<s[i];
        if(i!=s.length()-1)
        cout<<" ";
    }

    cout<<endl;
    return 0;
}
