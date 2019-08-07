#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,k;
const int maxn=1e3+7;
int f[maxn],vis[maxn];
bool O_o(int v)
{
    mem(vis,0);
    int have=0;
    int bound=n-1;
    for(int i=0;i<k;i++){
        have=v;
        int j=n;
        while(j>=0&&have>0){
            if(j==0&&vis[j]){
                break;
            }
            j=upper_bound(f,f+bound+1,have)-f;
            if(j>=n){
                j--;
            }
            while(j>=0){
                if(vis[j]  || have < f[j])
                j--;
                else
                break;
            }
            //cout<<j<<endl;
            if(bound==j){
                bound--;
            }

            vis[j]=1;
            have-=f[j];
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t,caa=0;
    cin>>t;
    while(t--){
        int sum=0,maxv=0;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>f[i];
            sum+=f[i];
            Max(maxv,f[i]);
        }
        sort(f,f+n);
        int act=ceil(sum/k);
        cout<<"Case #"<<++caa<<": ";
        for(int i=act;i<=act+maxv;i++){
            if(O_o(i)){
                cout<<i<<endl;
                break;
            }
        }

    }
    return 0;
}
/**
2
5 3
1 2 3 4 5
6  5
39 39 60 60 100 100
*/
