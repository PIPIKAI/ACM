#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int isa(char c)
{
    if(c>='0'&&c<='9')
        return 1;
    return 0;
}
void aton(long long a)
{
    string s;
    int co=0;
    while(a!=0)
    {
        long long b=a%26;
        a/=26;
        char c='A'+b-1;
        s[co++]=c;
    }
    for(int i=co-1;i>=0;i--)
    cout<<s[i];
}
void ntoa(char s[] ,int len)
{
    ll a=0,c=1;
    for(int co=len-1;co>=0;co--)
    {
        a=a+(c*(s[co]-'A'+1));
        c*=26;
    }
    cout<<a;
    return ;
}
void change1(string s)
{
    long long n=0,m=0;
    string a;
    int i=0;
    for( i=1;s[i]!='C';i++)
        n=n*10+(s[i]-'0');
    for( i++;i<s.size();i++)
        m=m*10+(s[i]-'0');
    aton(m);
   cout<<n<<endl;
}

void change2(string s)
{
    long long n=0;
    char  m[1000000];
    int co=0;
    int i=0;
    for( i=0;i<s.size();i++)
    {
        if(isa(s[i]))
            n=n*10+(s[i]-'0');
        else
            m[co++]=s[i];
    }
    m[co]='\0';
    cout<<"R"<<n<<"C";
    ntoa(m,co);
    cout<<endl;
}
int main()
{
int n;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    int flag=0;
    for(int j=1;j<s.length();j++)
    {
        int a=isa(s[j-1]);
        int b=isa(s[j]);
        if(a!=b)
            flag++;
    }

    if(flag==3)
    {
        change1(s);
    }
    else if(flag==1)
    {
        change2(s);
    }
}
    return 0;
}

