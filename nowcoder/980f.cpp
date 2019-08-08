#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;

unordered_map<int,int> f;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t, s;
        scanf("%d%d",&t,&s);
        if(t){
            if(f[s]==1){
                puts("yes");
            }
            else{
                 puts("no");
            }
        }
        else{
            f[s]=1;
        }
    }
    return 0;
}
