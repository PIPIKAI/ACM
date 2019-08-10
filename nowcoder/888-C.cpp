#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
#include<bitset>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
bitset<8> f[maxn];
bool juge(int x,int y){
    int tp=0,yy=0;
    for(int i=0;i<8;i++){
        if(f[x][i]==f[y][i]){
            tp++;
        }
        if(f[y][i]==1){
            yy++;
        }
    }
    return yy==4&&tp==4;
}
int main()
{
    std::ios::sync_with_stdio(false);
    for(int i=0;i<(1<<8);i++){
        f[i]=i;
    }
    int tp=0;
    for(int i=1;i;i++){
        if(juge(tp,i)){
            //cout<<f[i]<<endl;
            tp=i;
            cout<<i<<endl;
        }
    }
    return 0;
}