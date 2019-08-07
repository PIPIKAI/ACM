#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int f[28]={0};
string s;
int main()
{
    int t,sum=0;
    while(cin>>s)
    {
        memset(f,0,sizeof(f));
        sum=0;
        for(int i=0;i<s.size();i++)
        {
            t=s[i]-'a';
            f[t]++;
        }
        for(int i=0;i<=26;i++)
        {
            if(f[i])
            sum++;
        }
        cout<<sum<<endl;
        if(sum&1)
        cout<<"IGNORE HIM!"<<endl;
        else
        cout<<"CHAT WITH HER!"<<endl;
    }
    return 0;
}

