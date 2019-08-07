#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int f[5000050];
int main()
{
    std::ios::sync_with_stdio(false);
    while(~scanf("%d",&n)){
        bool flag=0;
        for(int i=0;i<n;i++){
            scanf("%d",f+i);
            if(i>1&&f[i] < f[i-1]+ f[i-2]){
                flag=1;
            }
        }
        flag ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
