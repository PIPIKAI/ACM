#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
    {
        char c='a'+(s[i]+n-'a')%26;
        cout<<c;
    }
   return 0;
}
