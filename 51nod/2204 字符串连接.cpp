#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
bool cmp(string s1,string s2){
    return s1+s2<s2+s1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    string s[101];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    return 0;
}
