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
int n,m;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    int ji=0,ou=0;
    cin>>T;
    while (T--)
    {
        cin>>n;
        int sum=n;
        for(int i=0,tp;i<n;i++){
            cin>>f[i];
        }
        for(int i=0,tp;i<n;i++){
            cin>>tp;
            if(tp==1 && 0==f[i]%2){
                sum++;
            }
            if(tp==2 && f[i]%2 ){
                sum++;
            }
        }
        if(sum%2){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}