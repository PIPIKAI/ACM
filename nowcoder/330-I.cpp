#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
bool juge(string str)
{
    for(int i = 0; i<str.size()/2;i++)
    {
        if(str[i] != str[str.size()-1-i])
            return false;
    }
    return true;
}
int main()
{
    string s;
    while(cin>>s)
    {
        bool flag = false;
        int i;
        for(i = 0; i<s.size()/2;i++)
            if(s[i] != s[s.size()-1-i])
                break;
        if(i == s.size()/2)
            flag = true;
        else
            flag = (juge(s.substr(i+1,s.size()-2*i-1)) || juge(s.substr(i,s.size()-2*i-1)));

        cout<< ((flag==true) ? "YES" : "NO")<<endl;
    };
    return 0;
}
