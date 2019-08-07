#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int juge[1000][2]={0};
string ans;
void solve()
{
    int a,b,c,p=0;
    cin>>a>>b;
    int i=a/b;
    ans+=(char) (i+'0');
    ans+=".";
    p=ans.size();
    int j=(a%b)*10;
    if(a%b)
        while(1)
        {
            i=j/b;
            j=(j%b)*10;
            ans+=(char)(i+'0');
            if(juge[j][0]!=0)
            {
                int s=juge[j][1];
                ans.insert(s,"(");
                break;
            }
            else
            {
                juge[j][0]++;
                juge[j][1]=ans.size()+p;
            }
        }
    cout<<ans<<endl;

}
int main()
{
    solve();
    return 0;
}
