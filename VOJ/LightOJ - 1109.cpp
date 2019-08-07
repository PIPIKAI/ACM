#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
const int maxn=1e3+1;
struct node
{
    int w,v;
}f[maxn];
void ini()
{
    for(int i=0;i<maxn;i++){
        int ct=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                ct++;
                if(i/j!=j){
                    ct++;
                }
            }
        }
        f[i].w=i;f[i].v=ct;
    }
}

bool cmp(node a,node b)
{
    return a.v==b.v ? a.w>b.w : a.v < b.v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,ca=0;
    ini();
    sort(f,f+maxn,cmp);
    cin>>t;
    while(t--){
        ca++;
        cin>>n;
        cout<<"Case "<<ca<<": "<<f[n].w<<endl;

    }
    return 0;
}
