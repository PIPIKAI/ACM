#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>n;
    cin>>s;
    int t=0;
    for(int i=0;i<n;i++){
        if(s[i]=='-'){
            t--;
            t=max(0,t);
        }
        else{
            t++;
        }
    }
    cout<<t<<endl;
    return 0;
}
