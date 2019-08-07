#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=5e4+7;
int n,m,cnt;
int f[maxn];
struct node
{
    int h,id,ans;
}qq[maxn];
struct node1
{
    int s,w;
}sum[maxn];
bool cmp1(node a,node b)
{
    return a.h<b.h;
}
bool cmp2(node a,node b)
{
    return a.id<b.id;
}
bool cmp3(node1 i,node1 j)
{
    return i.s<j.s;
}
int main()
{
    cin>>n>>m;
    int a[2]={-1,-1};
    std::ios::sync_with_stdio(false);
    for(int i=0;i<n;i++){
        cin>>a[i%2];
        if(a[(i+1)%2]!=a[i%2] ){
            f[cnt++]=a[i%2];
        }
    }
    for(int i=0;i<cnt;i++){
        if( (i==0||f[i]<f[i-1] )&&f[i]<f[i+1]){
            sum[i].w=1;
        }
        else if( f[i]>f[i-1] && (i==cnt-1 ||f[i]>f[i+1]) ){
            sum[i].w=-1;
        }
        else{
            sum[i].w=0;
        }
        sum[i].s=f[i];
    }
    for(int i=0;i<cnt;i++){
        cout<<sum[i].w<<" ";
    }
     cout<<endl;
     sort(sum,sum+cnt,cmp3);
    sort(f,f+cnt);

    for(int i=0;i<cnt;i++){
        cout<<sum[i].w<<" ";
    }
    for(int i=0;i<cnt;i++){
     sum[i+1].w+=sum[i].w;
    }
    sum[0].w=0;
    cout<<endl;

    for(int i=0,t;i<m;i++){
        cin>>t;
        qq[i].id=i;
        qq[i].h=t;
    }
    sort(qq,qq+m,cmp1);
    for(int i=0;i<m;i++){
        int j=upper_bound(f,f+cnt,qq[i].h)-f;
        qq[i].ans= 1+sum[j].w;

    }
    sort(qq,qq+m,cmp2);
    for(int i=0;i<m;i++){
        cout<<qq[i].ans<<endl;
    }
    return 0;
}
