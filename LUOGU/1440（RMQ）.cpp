#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
ll f[2000005][2];/// 0 表示值 1表示第几大
int main()
{
    std::ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    int tail=1,head=1;
    scanf("%d",&f[tail][0]);
    tail++;
    printf("0\n");
    for(int i=1;i<n;i++){
        if(i - f[head][1] >m){
            head++;
        }
        printf("%d\n",f[head][0]);
        int t;
        scanf("%d",&t);
        while(tail > head && t<f[tail-1][0]){
            tail--;
        }
        f[tail][0]= t;
        f[tail][1]= i;
        tail++;
    }
    return 0;
}
