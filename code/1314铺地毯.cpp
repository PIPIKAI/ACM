#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
struct node{
    int a,b,x,y;
};
int n,fx,fy,minx=1e9,miny=1e9,maxx=-1,maxy=-1;
node f[10050];
bool juge(int i){
    if(fx >=f[i].a && fx <= f[i].x && fy >=f[i].b && fy <= f[i].y ){
        return true;
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i].a>>f[i].b>>f[i].x>>f[i].y;
        f[i].x+=f[i].a;f[i].y+=f[i].b;
    }
    cin>>fx>>fy;
    for(int i=n;i>=1;i--){
    if(juge(i)){
        return cout<<i<<endl,0;
        }
    }
        cout<<-1<<endl;
    return 0;
}
