#include<bits/stdc++.h>
using namespace std;
int f[2000],cnt=0;
int t=0;
string s;
void ss()
{
    int len=s.length();
    int flag=0;
    for(int i=0;i<len;i++)
    {
        char c=s[i];
        if(flag&&c=='5')
        {
            f[cnt++]=t;t=0,flag=0;
        }
        else if(c!='5')
        {
            int aa=c-'0';
            t=t*10+aa;flag=1;
        }
    }
    if(flag)
        f[cnt++]=t;
}
int main()
{
    while(cin>>s)
    {
        cnt=t=0;
        ss();
        sort(f,f+cnt);
        for(int i=0;i<cnt;i++)
        {
            if(i!=cnt-1)
            cout<<f[i]<<" ";
        else
            cout<<f[i];
        }
        cout<<endl;
    }

    return 0;
}
