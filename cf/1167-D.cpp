#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=2e5+5;
string s;
int ans[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int deep=-1;
    cin>>n;
    cin>>s;
    for(int i=0,t=0;i<n;i++){
        if(s[i]=='('){
            t++;
            Max(deep,t);
           }
        else{
            t--;
        }
    }
    deep=(deep+1)/2;
    for(int i=0,t=0;i<n;i++){
        if(s[i]=='('){
            t++;
            if(t>deep){
                ans[i]=1;
            }
           }
        else{
            if(t>deep){
                ans[i]=1;
            }
                t--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];

    }
    cout<<endl;
    return 0;
}
