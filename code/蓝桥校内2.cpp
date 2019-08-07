#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n;
string s;
void solve(string ts)
{
    string tts;
    int cnt=1;
    for(int i=0;i<ts.size();i++)
    {
        if(ts[i]==ts[i+1])
        {
            cnt++;
        }
        else
        {
            char c=cnt+'0';
            tts = tts +c+ts[i];
            cnt=1;
        }
    }
    s=tts;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>s>>n)
    {
        for(int i=0;i<n;i++)
            solve(s);
        cout<<s<<endl;
    }
    return 0;
}
