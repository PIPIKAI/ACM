#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e3+7;
int n,m;
int a[maxn],b[maxn],f[maxn][maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        for(int i=0;i<1001;i++){
            for(int j=0;j<m;j++){
                f[i][j]=b[j]+i;
            }
        }
        for(int i=0;i<=1000;i++)
        {
            int aj=0,bj=0;
            bool flag=1;
            while(aj<n && bj <m){
                if(f[i][bj] > a[aj]){
                    aj++;
                }
                else if(f[i][bj] < a[aj]){
                    bj++;
                }
                else{
                    flag=0;
                    break;
                }
            }
               if(flag){
                ans=i;
                break;
               }
        }
        cout<<ans<<endl;
    }
    return 0;
}
