#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue <char > f[27];
int y=0;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	for(int i=0;i<4;i++)
    {
        string s;
        getline(cin,s);
        for(int j=0;j<s.length();j++)
        {
            if(s[j]>='A'&&s[j]<='Z')
            {
                f[s[j]-'A'].push('*');
                int t=f[s[j]-'A'].size();
                y=max(y,t);
            }
        }
    }
    for(int i=y;i>0;i--)
    {
        for(int j=0;j<26;j++)
        {
            if(f[j].size()>=i)
            {
                cout<<f[j].front()<<" ";
                f[j].pop();
            }
            else
                cout<<"  ";
        }
        cout<<endl;
    }
    for(int i=0;i<26;i++)
    {
        char c='A'+i;
        cout<<c<<" ";
    }
   return 0;
}
