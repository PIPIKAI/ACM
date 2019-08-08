#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,p;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>p;
    int len=0;
    int t=p;
    while(t){
        t/=10;
        len++;
    }
    if(len <= n){
        cout<<p;
        for(int i=0;i<n-len;i++){
            cout<<0;
        }
        cout<<endl;
    }
    else{
        cout<<"T_T"<<endl;
    }
    return 0;
}
