#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include<cstring>
#include<unordered_map>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
vector<int> f,k;
unordered_map<int,bool> fp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int t,i=0;i<n;i++){
        cin>>t;f.push_back(t);
    }
    k=f;
    sort(k.begin(),k.end());
    k.erase(unique(k.begin(),k.end()),k.end());
    for(int i=0;i<n;i++){
        f[i]=lower_bound(k.begin(),k.end(),f[i])-k.begin();
    }
    int ans=0;
    for(int i=0;i<n;i++){
        
        int take=0;
        for(int j=n-1;j>=0;j--){
            if(fp[f[j]]){
                break;
            }
            fp[f[j]]=1;
            take++;
        }
        ans=max(ans,i+take);
        for(int j=n-1;j>=n-take ;j--){
            fp[f[j]]=0;
        }
        if(fp[f[i]])
        break;
        fp[f[i]]=1;
    }
    cout<<n-ans<<endl;
    return 0;
}