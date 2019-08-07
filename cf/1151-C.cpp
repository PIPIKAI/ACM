#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
ll a[63]={1};
void ini(){
    for(int i=1;i<63;i++){
        a[i]=a[i-1]*2;
    }
}
int main()
{
    ini();
    std::ios::sync_with_stdio(false);
    ll l,r,k;
    cin>>l>>r;
    k=0;
    int i=0;
    while(k+a[i]<l){
        k+=a[i++];
    }
    return 0;
}
