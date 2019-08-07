#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
string s="ABCD";
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n
    n=n%4;
    if(n==1){
        cout<<0<<" "<<"A"<<endl;
    }
    else if(n==3){
        cout<<2<<" "<<"A"<<endl;
    }
    else if(n==2){
        cout<<1<<" "<<"B"<<endl;
    }
    else{
        cout<<1<<" "<<"A"<<endl;
    }
    return 0;
}
