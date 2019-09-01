#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
ll n,m;
ll a,b,c,d;
struct node 
{
    ll a,b;
    string ans;
};

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        string PT="";
        cin>>a>>b>>c>>d;
        node tp;
        tp.a=a;tp.b=b;tp.ans="";
        queue<node> q;
        q.push(tp);
        int flag=0;
        while(!q.empty())
        {
            tp=q.front();
            q.pop();
            if(tp.a==c && tp.b ==d){
                PT=tp.ans;
                flag=1;
                break;
            }
            node pt=tp;
            int i=c > tp.a ? 1 : 0;
            int j=2*tp.a-tp.b > tp.a ? 1:0;
            if(i==j ){
                pt.a=2*tp.a-tp.b;
                pt.ans+='B';
                q.push(pt);
            }
            pt=tp;
             i=d > tp.b ? 1 : 0;
             j=2*tp.b-tp.a > tp.b ? 1:0;
            if(i==j){
                pt.b=2*tp.b-tp.a;
                pt.ans+='A';
                q.push(pt);
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
            cout<<PT<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}