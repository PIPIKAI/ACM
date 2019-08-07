#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=10020;
const double pi=acos(-1);
int n,m;
double l;
double ans=0;
struct node{
    double x,y;
}f[maxn],q[maxn];
double dis(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Cha(node a,node b,node c){
    return a.x*b.y+b.x*c.y+a.y*c.x-b.y*c.x-a.y*b.x-c.y*a.x;
}
bool cmp(node a,node b){
    double pp=Cha(f[0],a,b);
    return pp==0 ? dis(a,f[0])<dis(b,f[0]) : pp>0 ;
}
int main()
{
    std::ios::sync_with_stdio(false);
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>f[i].x>>f[i].y;
        }
        if(n==1){
            printf("%.2lf\n",0);
        }
        else if(n==2){
            printf("%.2lf\n",dis(f[0],f[1]));
        }
        else{
            for(int i=1;i<n;i++){
                if(f[0].y > f[i].y){
                    swap(f[0],f[i]);
                }
                else if(f[0].y== f[i].y && f[i].x<f[0].x){
                    swap(f[0],f[i]);
                }
                }
                sort(f+1,f+n,cmp);
                q[0]=f[0];q[1]=f[1];
                int tail=1;
                for(int i=2;i<n;i++){
                    while(tail>0 && Cha(q[tail-1],q[tail],f[i])<=0) tail--;
                    q[++tail]=f[i];
                }
                for(int i=0;i<tail;i++){
                    ans+=dis(q[i],q[i+1]);
                }
                ans+=dis(q[0],q[tail]);

            printf("%.2lf\n",ans);
        }
    return 0;
}
