#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n;
string s;
void solve()
{
    int i,j;
    for( j=0,i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            reverse(s.begin()+j,s.begin()+i);
            j=i+1;
        }
    }
    reverse(s.begin()+j,s.end());
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n)
      {

        getline(cin,s);
        for(int i=0;i<n;i++)
        {
           getline(cin,s);z
           solve();
           cout<<s<<endl;
        }
      }
    return 0;
}




