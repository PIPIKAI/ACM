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
const int mod=998244353;
int n,m;
int phi[maxn], prime[maxn],er[maxn];
int tot;//tot计数，表示prime[N]中有多少质数 
void Euler(){
    er[0]=1;
    er[1]=2;
    phi[1] = 1;
    for(int i = 2; i < maxn; i ++){
        er[i]=2*er[i-1];
        if(!phi[i]){
            phi[i] = i-1;
            prime[tot ++] = i;
        }
        for(int j = 0; j < tot && 1ll*i*prime[j] < maxn; j ++){
            if(i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j]-1);
            else{
                phi[i * prime[j] ] = phi[i] * prime[j];
                break;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    Euler();
    int T;cin>>T;
    while(T--){
        cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ll tp=(phi[i]*phi[j])%mod;
                sum= (sum+ tp* er[tp])%mod;
                //cout<<tp* er[tp]<<" ";
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}