#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
int n,m,minx=inf,miny=inf,maxx=-inf,maxy=-inf,ans=0;
struct node{
    int x, y;
};
node f[2000000];
int dx[4]={0,1,1,0};
int dy[4]={0,0,1,1};
bool juge(int x,int y){
    bool flag=0;
    for(int i=0,j=n-1;i<n;i++){
        if(min(f[i].y,f[j].y) < y && max(f[i].y,f[j].y) >= y){
            double temp=(double)f[i].x+(double)(((double)(y-f[i].y)/(double)(f[i].y-f[j].y))*((double)(f[i].x-f[j].x)));
            if(temp <x){
                flag=!flag;
            }

        }
        j=i;
    }
    return flag;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i].x>>f[i].y;
        minx=min(f[i].x,minx);
        miny=min(f[i].y,miny);
        maxx=max(f[i].x,maxx);
        maxy=max(f[i].y,maxy);
    }
    for(int i=minx;i<=maxx;i++){
        for(int j=miny;j<=maxy;j++){
            int flag=0;
            for(int k=0;k<4;k++){
                if(juge(i+dx[k] ,j+dy[k])){
                    flag++;
                }
                else{
                    break;
                }
            }
            if(flag==4){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
