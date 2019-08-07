#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
string s;
int b,a;
void solve()
{
    int slen=s.length();
    int k=s[0]-'0';
        for(int i=0;i<slen-1;i++){
                k=k*10+(s[i+1]-'0');
                k=k%b;
            }
    cout<<k<<endl;
}
int main()
{
    while(cin>>s>>b)
    {
        solve();
    }
    return 0;
}
