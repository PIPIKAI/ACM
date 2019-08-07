#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int year,mon,day,hour,feng,miao;
const int mod=100;
int t;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%4d-%2d-%2d %2d:%2d:%2d",&year,&mon,&day,&hour,&feng,&miao);
        int ans=( (0-miao)+ (0-feng)*60 +1000000 )%mod;
        printf("%d\n",ans);
    }
    return 0;
}
