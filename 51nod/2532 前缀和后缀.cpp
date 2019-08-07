#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    string s[102];
    n=2*n-2;
    for(int i=0;i<n;i++){
        cin>>s[i];
        string t=s[i];
        reverse(s[i].begin(),s[i].end());
        if(t<s[i]){
            s[i]=t;
        }
    }
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])
        {
           return  cout<<"Impossible"<<endl,0;
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}
