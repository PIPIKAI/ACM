#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int f[3002][3002][52]={0};
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b,y,x,kind,nmb;
    while(m--){
        int c;
        cin>>c;
        if(c=='P'){
            cin>>a>>b>>x>>y>>k;
            for(int i=0;i<k;i++){
                cin>>kind>>nmb;
            }
        }
        else{
            cin>>a>>b>>x>>y;
            for(int i=1;i<=50;i++){
                f[]
            }
        }
    }
    return 0;
}
