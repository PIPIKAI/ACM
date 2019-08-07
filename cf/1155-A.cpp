#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
int n;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    int l,r;
    cin>>n;
    cin>>s;
    int flag=0;
    for(int i=1;i<s.size();i++){
        if( (int)s[i-1] > (int)s[i])
        {
            flag=1;
            l=i;
            r=i+1;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        cout<<l<<" "<<r<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
