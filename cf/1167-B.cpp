#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=5e5+7;
int n,m;
int f[maxn],k[maxn],nums[maxn];
int find(int x)
{
    while(f[x]!=x){
        x=f[x];
    }
    return x;
}
void mer(int x,int y)
{
    int f1=find(x);
    int f2=find(y);
    if(f1<f2){
        nums[f1]+=nums[f2];
            nums[f2]=0;
            f[f2]=f1;
    }
    if(f1>f2){
        nums[f2]+=nums[f1];
            nums[f1]=0;
            f[f1]=f2;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    for(int i=0;i<maxn;i++){
        f[i]=i;
        nums[i]=1;
    }
    cin>>n>>m;
    for(int t,i=0;i<m;i++){
        cin>>t;
        int a,b;
        for(int j=0;j<t;j++){
            cin>>k[j];
        }
        for(int j=0;j<t-1;j++){
            mer(k[j],k[j+1]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<nums[find(i)]<<" ";
    }
    cout<<endl;
    return 0;
}
/**
7 5
3 2 5 4
0
2 1 2
2 5 2
2 6 7
*/
