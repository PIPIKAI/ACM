#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>s;
    int l=1,r=0,c=0;
    for(int i=1;i<s.size();i++){
        if(s[i]=='('){
            l++;
           }
           else if(s[i]==')'){
            if(l==1){
                flag=0;
                break;
            }
            else{
                l--;
            }
           }
           else if(s[i]=='?'){
            l ++;
           }
    }
    return 0;
}
