#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e5+7;
int a[maxn],b[maxn];
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=1;i<=n;i++){
        cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        int i;
        stack<int> q1,q2;
        for( i=1;i<=n;i++){
            while(!q1.empty() && a[q1.top()] >a[i] ){
                q1.pop();
            }
            while(!q2.empty() && b[q2.top()] >b[i] ){
                q2.pop();
            }
            if(q1.size()-q2.size()){
                break;
            }
            q1.push(i);
            q2.push(i);
        }
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        cout<<i-1<<endl;
    }

    return 0;
}
