#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m,q;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>q;
    while(q--){
        cin>>n;
        int be;
        for(int i=0;i<n;i++){
            cin>>f[i];
            if(f[i]==1){
                be=i;
            }
        }
        int flag=0,cnt=0;
        int now=be;
        for(int i=0;i<n;i++){
            if(f[now]+1==f[(now+1)%n]){
                cnt++;
            }
            now=(now+1)%n;
        }
        //cout<<cnt<<endl;
        if(cnt==n-1){
            flag=1;
        }
        now=be;
        cnt=0;
       for(int i=1;i<n;i++){
            if(f[now]+1==f[(now-1+n)%n]){
                cnt++;
            }
            now=(now-1+n)%n;
        }
        //cout<<cnt<<endl;
        if(cnt==n-1){
            flag=1;
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}