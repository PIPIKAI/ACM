#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int a[500005],b[500005];
int main()
{
    std::ios::sync_with_stdio(false);
    int q;
    cin>>q;


    while(q--){
        int ans=inf;
        cin>>n>>m;
        vector<string>s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        vector<int>a(n);
        vector<int>b(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s[i][j]=='.'?a[i]++,b[j]++:0;
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    ans=min(a[i]+b[j]- (s[i][j]=='.'),ans);
                }
            }
        cout<<ans<<endl;
    }




    return 0;
}
